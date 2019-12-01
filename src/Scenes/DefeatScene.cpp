//
// Created by romane on 28/11/2019.
//

#include <memory>
#include "DefeatSystem.hpp"
#include "ButtonColorSystem.hpp"
#include "ParallaxSystem.hpp"
#include "DefeatScene.hpp"
#include "DisplaySystem.hpp"

ecs::DefeatScene::DefeatScene(std::shared_ptr<Ecs> &ecs) : _ecs(ecs)
{
    _ecs->getEntityManager()->deleteAll();
    _ecs->getSystemManager()->deleteAll();

    // TODO use system Factory inside ecs
    _ecs->getSystemManager()->addSystem(std::make_shared<system::DisplaySystem>(_ecs->getManagerWrapper(), _ecs->getEntityFactory(), _ecs->getSystemManager()->getEntitiesToDelete()));
    _ecs->getSystemManager()->addSystem(std::make_shared<system::DefeatSystem>(_ecs->getManagerWrapper(), _ecs->getEntityFactory(), _ecs->getSystemManager()->getEntitiesToDelete()));
    _ecs->getSystemManager()->addSystem(std::make_shared<system::ButtonColorSystem>(_ecs->getManagerWrapper(), _ecs->getEntityFactory(), _ecs->getSystemManager()->getEntitiesToDelete()));
    _ecs->getSystemManager()->addSystem(std::make_shared<system::ParallaxSystem>(_ecs->getManagerWrapper(), _ecs->getEntityFactory(), _ecs->getSystemManager()->getEntitiesToDelete()));

    _ecs->getEntityFactory()->createEntity("BackgroundWithoutTitle");
    _ecs->getEntityFactory()->createEntity("Stars");
    _ecs->getEntityFactory()->createEntity("Defeat");
    _ecs->getEntityFactory()->createEntity("Menu");
}