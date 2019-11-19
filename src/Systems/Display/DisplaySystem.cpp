/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** DisplaySystem.cpp
*/

#include "Physics/Position.hpp"
#include "Physics/Velocity.hpp"
#include "DisplaySystem.hpp"
#include <iostream>

namespace ecs::system
{
    DisplaySystem::DisplaySystem(std::shared_ptr<entities::IEntityManager> &entityManager, std::shared_ptr<ecs::components::IComponentManager> &componentManager, std::list<int> &entitiesToDelete) : 
    ASystem(entityManager, componentManager, entitiesToDelete)
    {
    }
    
    DisplaySystem::~DisplaySystem()
    {
    }

    void DisplaySystem::update()
    {
        for (auto &it : _entityManager->getAllEntities()) {
            auto components = _componentManager->getPhysicComponents(it->getID());
            for (auto &it2 : components) {
                if (it2->getType() == std::type_index(typeid(ecs::components::Velocity))) {
                    auto speed = std::dynamic_pointer_cast<ecs::components::Velocity>(it2);
                    for (auto &it3 : components) {
                        if (it3->getType() == std::type_index(typeid(ecs::components::Position))) {
                            auto position = std::dynamic_pointer_cast<ecs::components::Position>(it3);

                            position->setX(position->getX() + speed->getValue());
                            std::cout << "Update position : " << position->getX() << std::endl;

                        }
                    }
                }
            }
        }
    }
}