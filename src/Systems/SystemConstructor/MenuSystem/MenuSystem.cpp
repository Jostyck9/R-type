/*DisplaySystem
** EPITECH PROJECT, 2019
** R-type
** File description:
** MenuSystem.cpp
*/

#include <iostream>
#include <ComponentExceptions.hpp>
#include <Display/Button.hpp>
#include "DisplaySystem.hpp"
#include "MenuSystem.hpp"

using namespace ecs::system;

MenuSystem::MenuSystem(std::shared_ptr<ManagerWrapper> &managerWrapper, std::shared_ptr<ecs::entities::IEntityFactory> &entityFactory, std::list<int> &entitiesToDelete)
        : ASystem(managerWrapper, entityFactory, entitiesToDelete) {
}

SystemResponse MenuSystem::update()
{
    std::vector<std::shared_ptr<ecs::components::Button>> allButtons;
    auto keys = _managerWrapper->getRenderManager()->getKeysMap();

    for (auto &it : _managerWrapper->getEntityManager()->getAllEntities()) {
        try {
            allButtons.push_back(std::dynamic_pointer_cast<ecs::components::Button>(_managerWrapper->getComponentManager()->getDisplayComponentOfSpecifiedType(it->getID(), std::type_index(typeid(ecs::components::Button)))));
        } catch (const ComponentExceptions &e) {
        }
    }
    // std::cout << (keys[ecs::input::RIGHT] == IRenderManager::RELEASED) << std::endl;
    size_t i = 0;
    for (; i < allButtons.size(); i++) {
        if (allButtons[i]->getIsSelected()) {
            if (keys[ecs::input::RIGHT] == IRenderManager::RELEASED) {
                allButtons[i]->setIsSelected(false);
                if (i + 1 < allButtons.size())
                    allButtons[i + 1]->setIsSelected(true);
            } else if (keys[ecs::input::LEFT] == IRenderManager::RELEASED) {
                allButtons[i]->setIsSelected(false);
                if (i != 0)
                    allButtons[i - 1]->setIsSelected(true);
            }
            return SystemResponse();
        }
    }
    if (i >= allButtons.size() && !allButtons.empty())
        allButtons[0]->setIsSelected(true);
    return SystemResponse();
}
