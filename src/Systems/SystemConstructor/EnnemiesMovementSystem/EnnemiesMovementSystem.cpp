/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** EnnemiesMovementSystem.cpp
*/

#include <iostream>
#include "Physics/Velocity.hpp"
#include "ComponentExceptions.hpp"
#include "EnnemiesMovementSystem.hpp"

namespace ecs::system
{

EnnemiesMovementSystem::EnnemiesMovementSystem(std::shared_ptr<IManagerWrapper> &managerWrapper, std::shared_ptr<ecs::entities::IEntityFactory> &entityFactory, std::list<int> &entitiesToDelete) : ASystem(managerWrapper, entityFactory, entitiesToDelete)
{
}

SystemResponse EnnemiesMovementSystem::update()
{
    std::shared_ptr<ecs::components::Velocity> velocityComp;
    for (auto &it : _managerWrapper->getEntityManager()->getAllEntities())
    {
        try
        {
            std::shared_ptr<ecs::components::EnnemiesController> controller = std::dynamic_pointer_cast<ecs::components::EnnemiesController>(_managerWrapper->getComponentManager()->getGameLogicComponentOfSpecifiedType(it->getID(), std::type_index(typeid(ecs::components::EnnemiesController))));
            if (controller->getTimer().getElapsedSeconds() < controller->getInterval()) {
                continue;
            } else {
            velocityComp = std::dynamic_pointer_cast<ecs::components::Velocity>(_managerWrapper->getComponentManager()->getPhysicComponentOfSpecifiedType(it->getID(), std::type_index(typeid(ecs::components::Velocity))));
            updateVelocityOnPattern(controller, velocityComp);
            controller->getTimer().restart();
            }
        }
        catch (const ComponentExceptions &e)
        {           
        }
    }
    return SystemResponse();
}

void EnnemiesMovementSystem::updateVelocityOnPattern(std::shared_ptr<ecs::components::EnnemiesController> &controller, std::shared_ptr<ecs::components::Velocity> &velocityComp)
{
    if (controller->getShipType() == "Basic")
        return;
    if (controller->getShipType() == "Wave") {
        velocityComp->setVelocityY(velocityComp->getVelocityY() * (-1));
    }
}
} // namespace ecs::system
