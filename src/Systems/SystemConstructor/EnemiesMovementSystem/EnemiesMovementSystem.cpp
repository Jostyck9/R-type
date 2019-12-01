/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** EnemiesMovementSystem.cpp
*/

#include <iostream>
#include <GameLogic/Damage.hpp>
#include <GameLogic/EnemyShoot.hpp>
#include "EnemyShoot.hpp"
#include "Damage.hpp"
#include "Health.hpp"
#include "Velocity.hpp"
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

    for (size_t i = 0; i < entities.size(); i++) {
        try {
            std::shared_ptr<ecs::components::PlayerController> playerCtrl = std::dynamic_pointer_cast<ecs::components::PlayerController>(_managerWrapper->getComponentManager()->getGameLogicComponentOfSpecifiedType(entities[i]->getID(), std::type_index(typeid(ecs::components::PlayerController))));
            playerPos = std::dynamic_pointer_cast<ecs::components::Position>(_managerWrapper->getComponentManager()->getPhysicComponentOfSpecifiedType(entities[i]->getID(), std::type_index(typeid(ecs::components::Position))));
            spawnRandomEnemies(playerCtrl);
        } catch (const ComponentExceptions &e) {}
        try {
            std::shared_ptr<ecs::components::EnemiesController> controller = std::dynamic_pointer_cast<ecs::components::EnemiesController>(_managerWrapper->getComponentManager()->getGameLogicComponentOfSpecifiedType(entities[i]->getID(), std::type_index(typeid(ecs::components::EnemiesController))));
            std::shared_ptr<ecs::components::Position> pos = std::dynamic_pointer_cast<ecs::components::Position>(_managerWrapper->getComponentManager()->getPhysicComponentOfSpecifiedType(entities[i]->getID(), std::type_index(typeid(ecs::components::Position))));
            std::shared_ptr<ecs::components::Sprite> sprite = std::dynamic_pointer_cast<ecs::components::Sprite>(_managerWrapper->getComponentManager()->getDisplayComponentOfSpecifiedType(entities[i]->getID(), std::type_index(typeid(ecs::components::Sprite))));

            auto positionComp = std::reinterpret_pointer_cast<ecs::components::Position>(_managerWrapper->getComponentManager()->getPhysicComponentOfSpecifiedType(entities[i]->getID(), std::type_index(typeid(ecs::components::Position))));
            auto enemyShootComp = std::reinterpret_pointer_cast<ecs::components::EnemyShoot>(_managerWrapper->getComponentManager()->getGameLogicComponentOfSpecifiedType(entities[i]->getID(), std::type_index(typeid(ecs::components::EnemyShoot))));
            if (enemyShootComp->getCanShoot() && enemyShootComp->getBulletTimer().getElapsedMilliseconds() >= enemyShootComp->getBulletTimer().getEndTime()) {
                _entityFactory->createEntity("EnemyBullet", std::make_pair(positionComp->getPosition().first,
                                                                           positionComp->getPosition().second + 50));
                enemyShootComp->getBulletTimer().restart(enemyShootComp->getEndTime());
            }
            if (controller->getTimer().getElapsedSeconds() < controller->getInterval())
                continue;
            else {
                velocityComp = std::dynamic_pointer_cast<ecs::components::Velocity>(_managerWrapper->getComponentManager()->getPhysicComponentOfSpecifiedType(entities[i]->getID(), std::type_index(typeid(ecs::components::Velocity))));
                updateVelocityOnPattern(controller, velocityComp, playerPos, pos);
                controller->getTimer().restart();
            }
            std::map<size_t, std::string> collidedTags = std::reinterpret_pointer_cast<ecs::components::Collision>(_managerWrapper->getComponentManager()->getPhysicComponentOfSpecifiedType(entities[i]->getID(), std::type_index(typeid(ecs::components::Collision))))->getCollidedTags();
            for (auto it = collidedTags.begin(); it != collidedTags.end(); it ++) {
                if (it->second == "Bullet") {
                    auto healthComp = std::reinterpret_pointer_cast<ecs::components::Health>(
                            _managerWrapper->getComponentManager()->getGameLogicComponentOfSpecifiedType(
                                    entities[i]->getID(),
                                    std::type_index(typeid(ecs::components::Health))));
                    _entitiesToDelete.push_front(it->first);
                    try {
                        auto damage = std::reinterpret_pointer_cast<ecs::components::Damage>(
                                _managerWrapper->getComponentManager()->getGameLogicComponentOfSpecifiedType(
                                        it->first, std::type_index(typeid(ecs::components::Damage))));
                        healthComp->setValue(healthComp->getValue() - damage->getValue());
                    } catch (const ComponentExceptions &e) {
                        healthComp->setValue(healthComp->getValue() - 1);
                        continue;
                    }
                    if (healthComp->getValue() <= 0)
                        _entitiesToDelete.push_front(entities[i]->getID());
                }
                if (it->second == "Player")
                    _entitiesToDelete.push_front(entities[i]->getID());
            }
        } catch (const ComponentExceptions &e) {}
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
            velocityComp->setVelocityY((playerPos->getY() - pos->getY()) * (1.02));
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
            break;
        case 5:
            _entityFactory->createEntity("Enemy", pos);
            break;
        case 6:
            _entityFactory->createEntity("Enemy", pos);
            break;
        case 7:
            _entityFactory->createEntity("EnemyType03", pos);
            break;
        case 8:
            _entityFactory->createEntity("Enemy", pos);
            break;
        case 9:
            _entityFactory->createEntity("Enemy", pos);
            break;
        case 10:
            _entityFactory->createEntity("EnemyType02", pos);
            break;
        default:
            break;
        }
        controller->getCreationTimer().restart();
        return;
    }
}

} // namespace ecs::system
