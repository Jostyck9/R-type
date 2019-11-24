/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** MovementSystem.cpp
*/

#include <iostream>
#include "ComponentExceptions.hpp"
#include "MovementSystem.hpp"
#include "Position.hpp"
#include "Rotation.hpp"
#include "Velocity.hpp"

using namespace ecs::system;

MovementSystem::MovementSystem(std::shared_ptr<ecs::entities::IEntityManager> &entityManager,
                               std::shared_ptr<ecs::components::IComponentManager> &componentManager,
                               std::list<int> &entitiesToDelete) : ASystem(entityManager, componentManager, entitiesToDelete)
{
}

MovementSystem::~MovementSystem()
{
}

void MovementSystem::update()
{
    for (auto &it : _entityManager->getAllEntities())
    {
        try {
            auto position = _componentManager->getPhysicComponentOfSpecifiedType(it, std::type_index(typeid(ecs::components::Position)));
            auto rotation = _componentManager->getPhysicComponentOfSpecifiedType(it, std::type_index(typeid(ecs::components::Rotation)));
            auto velocit = _componentManager->getPhysicComponentOfSpecifiedType(it, std::type_index(typeid(ecs::components::Velocity)));
        } catch (ComponentExceptions &e) {
            std::cerr << e.what() << " : at " << e.where() << std::endl;
        }
    }
}