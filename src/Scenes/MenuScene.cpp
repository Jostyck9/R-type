//
// Created by romane on 28/11/2019.
//

#include <memory>
#include <SystemConstructor/MenuSystem/MenuSystem.hpp>
#include <SystemConstructor/ButtonColorSystem/ButtonColorSystem.hpp>
#include "MenuScene.hpp"
#include "DisplaySystem.hpp"

ecs::MenuScene::MenuScene(std::shared_ptr<Ecs> &ecs) : _ecs(ecs)
{
    _ecs->getEntityManager()->deleteAll();
    _ecs->getSystemManager()->deleteAll();

    // TODO use system Factory inside ecs
    _ecs->getSystemManager()->addSystem(std::make_shared<system::DisplaySystem>(_ecs->getManagerWrapper(), _ecs->getEntityFactory(), _ecs->getSystemManager()->getEntitiesToDelete()));
    _ecs->getSystemManager()->addSystem(std::make_shared<system::MenuSystem>(_ecs->getManagerWrapper(), _ecs->getEntityFactory(), _ecs->getSystemManager()->getEntitiesToDelete()));
    _ecs->getSystemManager()->addSystem(std::make_shared<system::ButtonColorSystem>(_ecs->getManagerWrapper(), _ecs->getEntityFactory(), _ecs->getSystemManager()->getEntitiesToDelete()));

    _ecs->getEntityFactory()->createEntity("BackgroundMenu");
    _ecs->getEntityFactory()->createEntity("Play");
    _ecs->getEntityFactory()->createEntity("Stop");
}