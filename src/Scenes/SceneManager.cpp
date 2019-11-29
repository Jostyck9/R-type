//Input
// Created by romane on 28/11/2019.
//

#include <iostream>
#include "MenuScene.hpp"
#include "SceneManager.hpp"
#include "BackgroundMenuEntity.hpp"
#include "PlayEntity.hpp"
#include "StopEntity.hpp"

namespace ecs {

    SceneManager::SceneManager() : _ecs(std::make_shared<Ecs>())
    {
        _ecs->getRenderManager()->init();

        _ecs->getEntityFactory()->addEntityConstructor(std::make_shared<entities::BackgroundMenuEntity>());
        _ecs->getEntityFactory()->addEntityConstructor(std::make_shared<entities::PlayEntity>());
        _ecs->getEntityFactory()->addEntityConstructor(std::make_shared<entities::StopEntity>());

        createMenu();
        run();
    }

    void SceneManager::createMenu()
    {
        _current = std::make_shared<MenuScene>(_ecs);
    }

    void SceneManager::run()
    {
        bool isPlaying = true;

        while (isPlaying) {
            _ecs->getSystemManager()->updateAll();
            isPlaying = _ecs->getRenderManager()->eventUpdate();
        }
    }
}