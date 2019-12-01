/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** EnemiesMovementSystem.cpp
*/

#include <iostream>
#include "Physics/Velocity.hpp"
#include "ComponentExceptions.hpp"
#include "PlayerController.hpp"
#include "EnemiesMovementSystem.hpp"

namespace ecs::system
{

EnemiesMovementSystem::EnemiesMovementSystem(std::shared_ptr<IManagerWrapper> &managerWrapper, std::shared_ptr<ecs::entities::IEntityFactory> &entityFactory, std::list<int> &entitiesToDelete) : ASystem(managerWrapper, entityFactory, entitiesToDelete)
{
}

SystemResponse EnemiesMovementSystem::update()
{
    std::shared_ptr<ecs::components::Velocity> velocityComp;
    auto entities = _managerWrapper->getEntityManager()->getAllEntities();

    for (size_t i = 0; i < entities.size(); i++)
    {
        try {
            std::shared_ptr<ecs::components::PlayerController> playerCtrl = std::dynamic_pointer_cast<ecs::components::PlayerController>(_managerWrapper->getComponentManager()->getGameLogicComponentOfSpecifiedType(entities[i]->getID(), std::type_index(typeid(ecs::components::PlayerController))));
            spawnRandomEnnemies(playerCtrl);
        }
        catch (const ComponentExceptions &e)
        {}
        try
        {
            std::shared_ptr<ecs::components::EnemiesController> controller = std::dynamic_pointer_cast<ecs::components::EnemiesController>(_managerWrapper->getComponentManager()->getGameLogicComponentOfSpecifiedType(entities[i]->getID(), std::type_index(typeid(ecs::components::EnemiesController))));
            std::shared_ptr<ecs::components::Position> pos = std::dynamic_pointer_cast<ecs::components::Position>(_managerWrapper->getComponentManager()->getPhysicComponentOfSpecifiedType(entities[i]->getID(), std::type_index(typeid(ecs::components::Position))));
            std::shared_ptr<ecs::components::Sprite> sprite = std::dynamic_pointer_cast<ecs::components::Sprite>(_managerWrapper->getComponentManager()->getDisplayComponentOfSpecifiedType(entities[i]->getID(), std::type_index(typeid(ecs::components::Sprite))));

            if (pos->getX() < (0 - sprite->getRect().getWidth()))
            {
                _entitiesToDelete.push_front(entities[i]->getID());
            }
            if (controller->getTimer().getElapsedSeconds() < controller->getInterval())
            {
                continue;
            }
            else
            {
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

void EnemiesMovementSystem::updateVelocityOnPattern(std::shared_ptr<ecs::components::EnemiesController> &controller, std::shared_ptr<ecs::components::Velocity> &velocityComp)
{
    if (controller->getShipType() == "Basic")
        return;
    if (controller->getShipType() == "Wave")
    {
        velocityComp->setVelocityY(velocityComp->getVelocityY() * (-1));
    }
}

void EnemiesMovementSystem::spawnRandomEnnemies(std::shared_ptr<ecs::components::PlayerController> &controller)
{
    if (controller->getCreationTimer().getElapsedSeconds() > controller->getCreationInterval())
    {
        std::pair<int, int> pos(1500, 400);
        pos.second = (rand() % 700 + 100);
        int i = (rand() % 5);
        switch (i)
        {
        case 0:
            _entityFactory->createEntity("Enemy", pos);
            break;
        case 1:
            _entityFactory->createEntity("Enemy", pos);
            break;
        case 2:
            _entityFactory->createEntity("Enemy", pos);
            break;
        case 3:
            _entityFactory->createEntity("Enemy", pos);
            break;
        case 4:
            _entityFactory->createEntity("EnemyType01", pos);
            break;
        default:
            break;
        }
        controller->getCreationTimer().restart();
        return;
    }
}

} // namespace ecs::system
