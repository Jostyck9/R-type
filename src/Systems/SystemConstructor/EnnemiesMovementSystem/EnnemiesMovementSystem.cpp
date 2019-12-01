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
    auto entities = _managerWrapper->getEntityManager()->getAllEntities();

    for (size_t i = 0; i < entities.size(); i++) {
        try {
            auto positionComp = std::reinterpret_pointer_cast<ecs::components::Position>(
                    _managerWrapper->getComponentManager()->getPhysicComponentOfSpecifiedType(entities[i]->getID(),
                                                                                              std::type_index(
                                                                                                      typeid(ecs::components::Position))));
            std::shared_ptr<ecs::components::EnnemiesController> controller = std::dynamic_pointer_cast<ecs::components::EnnemiesController>(_managerWrapper->getComponentManager()->getGameLogicComponentOfSpecifiedType(entities[i]->getID(), std::type_index(typeid(ecs::components::EnnemiesController))));
            if (controller->getBulletTimer().getElapsedMilliseconds() >=
                controller->getBulletTimer().getEndTime()) {
                _entityFactory->createEntity("EnemyBullet", std::make_pair(positionComp->getPosition().first,
                                                                      positionComp->getPosition().second));
                controller->getBulletTimer().restart(2000);
            }
            if (controller->getTimer().getElapsedSeconds() < controller->getInterval()) {
                continue;
            } else {
            velocityComp = std::dynamic_pointer_cast<ecs::components::Velocity>(_managerWrapper->getComponentManager()->getPhysicComponentOfSpecifiedType(entities[i]->getID(), std::type_index(typeid(ecs::components::Velocity))));
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
