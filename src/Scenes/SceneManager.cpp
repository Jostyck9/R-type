//Input
// Created by romane on 28/11/2019.
//

#include <SystemManager/SystemManager.hpp>
#include <iostream>
#include "MenuScene.hpp"
#include "EntityFactory.hpp"
#include "SceneManager.hpp"
#include "BackgroundMenuEntity.hpp"
#include "PlayEntity.hpp"
#include "StopEntity.hpp"

namespace ecs {

    SceneManager::SceneManager()
    {
        _managerWrapper = std::make_shared<ecs::ManagerWrapper>();
        _systemManager = std::make_shared<system::SystemManager>(_managerWrapper);
        _entityFactory = std::make_shared<ecs::entities::EntityFactory>(_managerWrapper->getEntityManager(), _managerWrapper->getComponentManager());

        _managerWrapper->getRenderManager()->init();

        _entityFactory->addEntityConstructor(std::make_shared<entities::BackgroundMenuEntity>());
        _entityFactory->addEntityConstructor(std::make_shared<entities::PlayEntity>());
        _entityFactory->addEntityConstructor(std::make_shared<entities::StopEntity>());

        createMenu();
        run();
    }

    void SceneManager::createMenu()
    {
        _current = std::make_shared<MenuScene>(_managerWrapper, _systemManager, _entityFactory);
    }

    void SceneManager::run()
    {
        bool isPlaying = true;

        while (isPlaying) {
            _systemManager->updateAll();
            isPlaying = _managerWrapper->getRenderManager()->eventUpdate();
        }
    }

}