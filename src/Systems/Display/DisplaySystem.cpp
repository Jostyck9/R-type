/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** DisplaySystem.cpp
*/

#include "Physics/Position.hpp"
#include "Physics/Velocity.hpp"
#include "DisplaySystem.hpp"
#include "Physics/Collision.hpp"
#include "ComponentExceptions.hpp"
#include <iostream>

namespace ecs::system
{
    DisplaySystem::DisplaySystem(std::shared_ptr<ecs::entities::IEntityManager> &entityManager, std::shared_ptr<ecs::components::IComponentManager> &componentManager, std::list<int> &entitiesToDelete) : 
    ASystem(entityManager, componentManager, entitiesToDelete)
    {
    }
    
    DisplaySystem::~DisplaySystem()
    {
    }

    void DisplaySystem::update()
    {
        for (auto &it : _entityManager->getAllEntities()) {
            // auto VelocityComponent = _componentManager->getPhysicComponentOfSpecifiedType(it->getID(),std::type_index(typeid(ecs::components::Velocity)));
            // auto speed = std::dynamic_pointer_cast<ecs::components::Velocity>(VelocityComponent);
            auto PosComponent = _componentManager->getPhysicComponentOfSpecifiedType(it->getID(),std::type_index(typeid(ecs::components::Position)));
            auto position = std::dynamic_pointer_cast<ecs::components::Position>(PosComponent);
            // position->setX(position->getX() + speed->getValue());
            std::cout << "Update position : " << int(position->getX()) << " " << int(position->getY()) << std::endl;
            try {
                auto colision = std::reinterpret_pointer_cast<ecs::components::Collision>(_componentManager->getPhysicComponentOfSpecifiedType(it->getID(), std::type_index(typeid(ecs::components::Collision))));
                for (auto &it2 : colision->getCollidedTags()) {
                    std::cout << "colision on " << it->getID() << " by " << it2.first << " on tag : " << it2.second << std::endl;
                }
            } catch (ComponentExceptions &e) {
            }
        }
    }
}