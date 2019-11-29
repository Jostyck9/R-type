/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** GameScene.cpp
*/

#include <memory>
#include <utility>
#include "EntityFactory.hpp"
#include "GameScene.hpp"
#include "ManagerWrapper.hpp"
#include "DisplaySystem.hpp"
#include "PlayerMovementSystem.hpp"
#include "EntityFactory.hpp"
#include "MovementSystem.hpp"

ecs::GameScene::GameScene(std::shared_ptr<Ecs> &ecs) : _ecs(ecs)
{
    _ecs->getEntityManager()->deleteAll();
    _ecs->getSystemManager()->deleteAll();

    // TODO use system Factory inside ecs
    _ecs->getSystemManager()->addSystem(std::make_shared<system::DisplaySystem>(_ecs->getManagerWrapper(), _ecs->getSystemManager()->getEntitiesToDelete()));
    _ecs->getSystemManager()->addSystem(std::make_shared<system::MovementSystem>(_ecs->getManagerWrapper(), _ecs->getSystemManager()->getEntitiesToDelete()));
    _ecs->getSystemManager()->addSystem(std::make_shared<system::PlayerMovementSystem>(_ecs->getManagerWrapper(), _ecs->getSystemManager()->getEntitiesToDelete()));
    _ecs->getEntityFactory()->createEntity("Player");
    _ecs->getEntityFactory()->createEntity("Bullet");
    _ecs->getEntityFactory()->createEntity("Ennemy");
}