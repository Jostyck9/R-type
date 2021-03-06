/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** GameScene.cpp
*/

#include <memory>
#include "GameScene.hpp"
#include "DisplaySystem.hpp"
#include "PlayerMovementSystem.hpp"
#include "EnemiesMovementSystem.hpp"
#include "AnimationSystem.hpp"
#include "MovementSystem.hpp"
#include "ParallaxSystem.hpp"

ecs::GameScene::GameScene(std::shared_ptr<Ecs> &ecs) : _ecs(ecs)
{
    _ecs->getEntityManager()->deleteAll();
    _ecs->getSystemManager()->deleteAll();

    // TODO use system Factory inside ecs
    _ecs->getSystemManager()->addSystem(std::make_shared<system::DisplaySystem>(_ecs->getManagerWrapper(), _ecs->getEntityFactory(), _ecs->getSystemManager()->getEntitiesToDelete()));
    _ecs->getSystemManager()->addSystem(std::make_shared<system::MovementSystem>(_ecs->getManagerWrapper(), _ecs->getEntityFactory(), _ecs->getSystemManager()->getEntitiesToDelete()));
    _ecs->getSystemManager()->addSystem(std::make_shared<system::PlayerMovementSystem>(_ecs->getManagerWrapper(), _ecs->getEntityFactory(), _ecs->getSystemManager()->getEntitiesToDelete()));
    _ecs->getSystemManager()->addSystem(std::make_shared<system::EnemiesMovementSystem>(_ecs->getManagerWrapper(), _ecs->getEntityFactory(), _ecs->getSystemManager()->getEntitiesToDelete()));
    _ecs->getSystemManager()->addSystem(std::make_shared<system::AnimationSystem>(_ecs->getManagerWrapper(), _ecs->getEntityFactory(), _ecs->getSystemManager()->getEntitiesToDelete()));
    _ecs->getSystemManager()->addSystem(std::make_shared<system::ParallaxSystem>(_ecs->getManagerWrapper(), _ecs->getEntityFactory(), _ecs->getSystemManager()->getEntitiesToDelete()));
    _ecs->getEntityFactory()->createEntity("GameBackground");
    _ecs->getEntityFactory()->createEntity("Planet");
    _ecs->getEntityFactory()->createEntity("PlanetRing");
    _ecs->getEntityFactory()->createEntity("Stars");
    _ecs->getEntityFactory()->createEntity("Player");
    _ecs->getEntityFactory()->createEntity("PlayerTwo", std::make_pair(30, 80));
    _ecs->getEntityFactory()->createEntity("Enemy", std::make_pair(1600, 400));
    _ecs->getEntityFactory()->createEntity("EnemyType01", std::make_pair(1650, 100));
    _ecs->getEntityFactory()->createEntity("EnemyType02", std::make_pair(1650, 700));
    _ecs->getEntityFactory()->createEntity("EnemyType03", std::make_pair(1650, 100));
}