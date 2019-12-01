/*DisplaySystem
** EPITECH PROJECT, 2019
** R-type
** File description:
** DefeatSystem.cpp
*/

#include <iostream>
#include "ComponentExceptions.hpp"
#include "Button.hpp"
#include "DisplaySystem.hpp"
#include "ManagerWrapper.hpp"
#include "DefeatSystem.hpp"

using namespace ecs::system;

DefeatSystem::DefeatSystem(std::shared_ptr<ecs::IManagerWrapper> &managerWrapper, std::shared_ptr<ecs::entities::IEntityFactory> &entityFactory, std::list<int> &entitiesToDelete)
        : ASystem(managerWrapper, entityFactory, entitiesToDelete) {
}

SystemResponse DefeatSystem::update()
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
            if (keys[ecs::input::SPACE] == IRenderManager::RELEASED) {
                return SystemResponse(allButtons[i]->getCmd(), allButtons[i]->getParameter());
            }
            return SystemResponse();
        }
    }
    if (i >= allButtons.size() && !allButtons.empty())
        allButtons[0]->setIsSelected(true);
    return SystemResponse();
}