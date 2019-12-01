/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** EnemiesMovementSystem.cpp
*/

#include <iostream>
#include "Physics/Velocity.hpp"
#include "ComponentExceptions.hpp"
#include "EnemiesMovementSystem.hpp"

namespace ecs::system
{

EnemiesMovementSystem::EnemiesMovementSystem(std::shared_ptr<IManagerWrapper> &managerWrapper, std::shared_ptr<ecs::entities::IEntityFactory> &entityFactory, std::list<int> &entitiesToDelete) : ASystem(managerWrapper, entityFactory, entitiesToDelete)
{
}

SystemResponse EnemiesMovementSystem::update()
{
    std::shared_ptr<ecs::components::Velocity> velocityComp;
    for (auto &it : _managerWrapper->getEntityManager()->getAllEntities())
    {
        try
        {
            std::shared_ptr<ecs::components::EnemiesController> controller = std::dynamic_pointer_cast<ecs::components::EnemiesController>(_managerWrapper->getComponentManager()->getGameLogicComponentOfSpecifiedType(it->getID(), std::type_index(typeid(ecs::components::EnemiesController))));
            std::shared_ptr<ecs::components::Position> pos = std::dynamic_pointer_cast<ecs::components::Position>(_managerWrapper->getComponentManager()->getPhysicComponentOfSpecifiedType(it->getID(), std::type_index(typeid(ecs::components::Position))));
            std::shared_ptr<ecs::components::Sprite> sprite = std::dynamic_pointer_cast<ecs::components::Sprite>(_managerWrapper->getComponentManager()->getDisplayComponentOfSpecifiedType(it->getID(), std::type_index(typeid(ecs::components::Sprite))));

            if (pos->getX() < (0 - sprite->getRect().getWidth())) {
                _entitiesToDelete.push_front(it->getID());
                std::cout << "deleted enemy" << std::endl;
            }
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

void EnemiesMovementSystem::updateVelocityOnPattern(std::shared_ptr<ecs::components::EnemiesController> &controller, std::shared_ptr<ecs::components::Velocity> &velocityComp)
{
    if (controller->getShipType() == "Basic")
        return;
    if (controller->getShipType() == "Wave") {
        velocityComp->setVelocityY(velocityComp->getVelocityY() * (-1));
    }
}
} // namespace ecs::system
