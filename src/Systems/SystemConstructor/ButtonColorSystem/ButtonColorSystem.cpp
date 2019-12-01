/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** ButtonColorSystem.cpp
*/

#include <iostream>
#include <ComponentExceptions.hpp>
#include <Display/Button.hpp>
#include "DisplaySystem.hpp"
#include "ButtonColorSystem.hpp"

using namespace ecs::system;

ButtonColorSystem::ButtonColorSystem(std::shared_ptr<ecs::IManagerWrapper> &managerWrapper, std::shared_ptr<ecs::entities::IEntityFactory> &entityFactory, std::list<int> &entitiesToDelete)
        : ASystem(managerWrapper, entityFactory, entitiesToDelete) {
}

SystemResponse ButtonColorSystem::update()
{
    std::shared_ptr<ecs::components::Text> textComp;
    std::shared_ptr<ecs::components::Button> buttonComp;

    for (auto &it : _managerWrapper->getEntityManager()->getAllEntities()) {
        try {
            textComp = std::dynamic_pointer_cast<ecs::components::Text>(_managerWrapper->getComponentManager()->getDisplayComponentOfSpecifiedType(it->getID(), std::type_index(typeid(ecs::components::Text))));
            buttonComp = std::dynamic_pointer_cast<ecs::components::Button>(_managerWrapper->getComponentManager()->getDisplayComponentOfSpecifiedType(it->getID(), std::type_index(typeid(ecs::components::Button))));
            if (buttonComp->getIsSelected()) {
                textComp->setColor(ecs::Color::YELLOW);
            } else
                textComp->setColor(ecs::Color::WHITE);
        } catch (const ComponentExceptions &e) {
        }
    }
    return SystemResponse();
}
