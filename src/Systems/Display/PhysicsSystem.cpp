/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** PhysicsSystem.cpp
*/

#include "Physics/Position.hpp"
#include "Physics/Velocity.hpp"
#include "PhysicsSystem.hpp"
#include <iostream>

namespace ecs::system
{
    PhysicsSystem::PhysicsSystem(std::shared_ptr<ManagerWrapper> &managerWrapper, std::list<int> &entitiesToDelete) : 
    ASystem(managerWrapper, entitiesToDelete)
    {
    }
    
    PhysicsSystem::~PhysicsSystem()
    {
    }

    void PhysicsSystem::update()
    {
        for (auto &it : _managerWrapper->getEntityManager()->getAllEntities()) {
            auto VelocityComponent = _managerWrapper->getComponentManager()->getPhysicComponentOfSpecifiedType(it->getID(),std::type_index(typeid(ecs::components::Velocity)));
            auto speed = std::dynamic_pointer_cast<ecs::components::Velocity>(VelocityComponent);
            auto PosComponent = _managerWrapper->getComponentManager()->getPhysicComponentOfSpecifiedType(it->getID(),std::type_index(typeid(ecs::components::Position)));
            auto position = std::dynamic_pointer_cast<ecs::components::Position>(PosComponent);
            position->setX(position->getX() + speed->getValue());
        }
    }
}