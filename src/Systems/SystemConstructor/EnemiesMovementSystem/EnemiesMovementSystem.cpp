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
    std::shared_ptr<ecs::components::Position> playerPos;
    auto entities = _managerWrapper->getEntityManager()->getAllEntities();

    for (size_t i = 0; i < entities.size(); i++)
    {
        try {
            std::shared_ptr<ecs::components::PlayerController> playerCtrl = std::dynamic_pointer_cast<ecs::components::PlayerController>(_managerWrapper->getComponentManager()->getGameLogicComponentOfSpecifiedType(entities[i]->getID(), std::type_index(typeid(ecs::components::PlayerController))));
            playerPos = std::dynamic_pointer_cast<ecs::components::Position>(_managerWrapper->getComponentManager()->getPhysicComponentOfSpecifiedType(entities[i]->getID(), std::type_index(typeid(ecs::components::Position))));
            spawnRandomEnemies(playerCtrl);

        }
        catch (const ComponentExceptions &e)
        {}
        try
        {
            std::shared_ptr<ecs::components::EnemiesController> controller = std::dynamic_pointer_cast<ecs::components::EnemiesController>(_managerWrapper->getComponentManager()->getGameLogicComponentOfSpecifiedType(entities[i]->getID(), std::type_index(typeid(ecs::components::EnemiesController))));
            std::shared_ptr<ecs::components::Position> pos = std::dynamic_pointer_cast<ecs::components::Position>(_managerWrapper->getComponentManager()->getPhysicComponentOfSpecifiedType(entities[i]->getID(), std::type_index(typeid(ecs::components::Position))));
            std::shared_ptr<ecs::components::Sprite> sprite = std::dynamic_pointer_cast<ecs::components::Sprite>(_managerWrapper->getComponentManager()->getDisplayComponentOfSpecifiedType(entities[i]->getID(), std::type_index(typeid(ecs::components::Sprite))));

            if (controller->getTimer().getElapsedSeconds() < controller->getInterval())
            {
                continue;
            }
            else
            {
                velocityComp = std::dynamic_pointer_cast<ecs::components::Velocity>(_managerWrapper->getComponentManager()->getPhysicComponentOfSpecifiedType(entities[i]->getID(), std::type_index(typeid(ecs::components::Velocity))));
                updateVelocityOnPattern(controller, velocityComp, playerPos, pos);
                controller->getTimer().restart();
            }
        }
        catch (const ComponentExceptions &e)
        {
        }
    }
    return SystemResponse();
}

void EnemiesMovementSystem::updateVelocityOnPattern(std::shared_ptr<ecs::components::EnemiesController> &controller, std::shared_ptr<ecs::components::Velocity> &velocityComp, std::shared_ptr<ecs::components::Position> playerPos, std::shared_ptr<ecs::components::Position> pos)
{
    if (controller->getShipType() == "Basic")
        return;
    if (controller->getShipType() == "Wave")
    {
        velocityComp->setVelocityY(velocityComp->getVelocityY() * (-1));
    }
    if (controller->getShipType() == "Kamikaze")
    {
        if (playerPos == nullptr) {
            velocityComp->setVelocityY(velocityComp->getVelocityY() * (-1));
            return;
        }
        if (playerPos->getY() == pos->getY())
            velocityComp->setVelocityX(-666);
        if (playerPos->getY() < pos->getY()) {
            velocityComp->setVelocityY((pos->getY() * (-1)));
            velocityComp->setVelocityX(-200);
        }
        else if (playerPos->getY() > pos->getY()) {
            velocityComp->setVelocityY((playerPos->getY() - pos->getY()) * (1,02));
            velocityComp->setVelocityX(-200);
        }
    }
}

void EnemiesMovementSystem::spawnRandomEnemies(std::shared_ptr<ecs::components::PlayerController> &controller)
{
    if (controller->getCreationTimer().getElapsedSeconds() > controller->getCreationInterval())
    {
        std::pair<int, int> pos(1580, 400);
        pos.second = (rand() % 700 + 50);
        int i = (rand() % 10);
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
            _entityFactory->createEntity("EnemyType02", pos);
        case 5:
            _entityFactory->createEntity("EnemyType01", pos);
            break;
        case 6:
            _entityFactory->createEntity("Enemy", pos);
            break;
        case 7:
            _entityFactory->createEntity("EnemyType03", pos);
            break;
        case 8:
            _entityFactory->createEntity("EnemyType03", pos);
            break;
        case 9:
            _entityFactory->createEntity("Enemy", pos);
            break;
            break;
        default:
            break;
        }
        controller->getCreationTimer().restart();
        return;
    }
}

} // namespace ecs::system