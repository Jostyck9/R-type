//
// Created by romane on 28/11/2019.
//

#include <memory>
#include <utility>
#include "EntityFactory.hpp"
#include "MenuScene.hpp"
#include "ManagerWrapper.hpp"
#include "DisplaySystem.hpp"
#include "EntityFactory.hpp"

ecs::MenuScene::MenuScene(const std::shared_ptr<ecs::ManagerWrapper>& managerWrapper, const std::shared_ptr<ecs::system::ISystemManager>& systemManager, const std::shared_ptr<ecs::entities::IEntityFactory>& entityFactory)
{
    _systemManager = systemManager;
    _managerWrapper = managerWrapper;
    _entityFactory = entityFactory;

    _entityManager = std::make_shared<ecs::entities::EntityManager>(_managerWrapper->getComponentManager());
    _entityManager->deleteAll();

    _systemManager->addSystem(std::make_shared<system::DisplaySystem>(_managerWrapper, _systemManager->getEntitiesToDelete()));

    _entityFactory->createEntity("BackgroundMenu");
    _entityFactory->createEntity("Play");
    _entityFactory->createEntity("Stop");
//    _systemManager->deleteAll();
}