//
// Created by romane on 28/11/2019.
//

#include <memory>
#include <utility>
#include <SystemConstructor/MenuSystem/MenuSystem.hpp>
#include <SystemConstructor/ButtonColorSystem/ButtonColorSystem.hpp>
#include "EntityFactory.hpp"
#include "MenuScene.hpp"
#include "ManagerWrapper.hpp"
#include "DisplaySystem.hpp"
#include "EntityFactory.hpp"

ecs::MenuScene::MenuScene(std::shared_ptr<Ecs> &ecs) : _ecs(ecs)
{
    _ecs->getEntityManager()->deleteAll();
    _ecs->getSystemManager()->deleteAll();

    // TODO use system Factory inside ecs
    _ecs->getSystemManager()->addSystem(std::make_shared<system::DisplaySystem>(_ecs->getManagerWrapper(), _ecs->getSystemManager()->getEntitiesToDelete()));
    _ecs->getSystemManager()->addSystem(std::make_shared<system::MenuSystem>(_ecs->getManagerWrapper(), _ecs->getSystemManager()->getEntitiesToDelete()));
    _ecs->getSystemManager()->addSystem(std::make_shared<system::ButtonColorSystem>(_ecs->getManagerWrapper(), _ecs->getSystemManager()->getEntitiesToDelete()));

    _ecs->getEntityFactory()->createEntity("BackgroundMenu");
    _ecs->getEntityFactory()->createEntity("Play");
    _ecs->getEntityFactory()->createEntity("Stop");
}