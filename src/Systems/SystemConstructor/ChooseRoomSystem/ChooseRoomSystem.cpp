/*DisplaySystem
** EPITECH PROJECT, 2019
** R-type
** File description:
** ChooseRoomSystem.cpp
*/

#include <iostream>
#include <ComponentExceptions.hpp>
#include <Display/Button.hpp>
#include "DisplaySystem.hpp"
#include "ManagerWrapper.hpp"
#include "ChooseRoomSystem.hpp"

using namespace ecs::system;

ChooseRoomSystem::ChooseRoomSystem(std::shared_ptr<ecs::ManagerWrapper> &managerWrapper, std::shared_ptr<ecs::entities::IEntityFactory> &entityFactory, std::list<int> &entitiesToDelete)
        : ASystem(managerWrapper, entityFactory, entitiesToDelete) {
}

SystemResponse ChooseRoomSystem::update()
{
    std::vector<std::shared_ptr<ecs::components::Button>> allButtons;
    auto keys = _managerWrapper->getRenderManager()->getKeysMap();

    for (auto &it : _managerWrapper->getEntityManager()->getAllEntities()) {
        try {
            allButtons.push_back(std::dynamic_pointer_cast<ecs::components::Button>(_managerWrapper->getComponentManager()->getDisplayComponentOfSpecifiedType(it->getID(), std::type_index(typeid(ecs::components::Button)))));
        } catch (const ComponentExceptions &e) {
        }
    }
    size_t i = 0;
    for (; i < allButtons.size(); i++) {
        if (allButtons[i]->getIsSelected()) {
            if (keys[ecs::input::DOWN] == IRenderManager::RELEASED) {
                allButtons[i]->setIsSelected(false);
                if (i + 1 < allButtons.size())
                    allButtons[i + 1]->setIsSelected(true);
            } else if (keys[ecs::input::UP] == IRenderManager::RELEASED) {
                allButtons[i]->setIsSelected(false);
                if (i != 0)
                    allButtons[i - 1]->setIsSelected(true);
                else
                    allButtons[allButtons.size() - 1]->setIsSelected(true);
            } else if (keys[ecs::input::SPACE] == IRenderManager::RELEASED) {
                return SystemResponse(allButtons[i]->getCmd(), allButtons[i]->getParameter());
            } else if (keys[ecs::input::LEFT] == IRenderManager::RELEASED) {
                allButtons[i]->setIsSelected(false);
                allButtons[allButtons.size() - 1]->setIsSelected(true);
            } else if (keys[ecs::input::RIGHT] == IRenderManager::RELEASED) {
                allButtons[i]->setIsSelected(false);
                allButtons[0]->setIsSelected(true);
            }
            return SystemResponse();
        }
    }
    if (i >= allButtons.size() && !allButtons.empty())
        allButtons[0]->setIsSelected(true);
    return SystemResponse();
}

const std::string ChooseRoomSystem::getName() const
{
    return ("ChooseRoom");
}