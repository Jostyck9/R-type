//Input
// Created by romane on 28/11/2019.
//

#include <iostream>
#include "SystemResponse.hpp"
#include "MenuScene.hpp"
#include "GameScene.hpp"
#include "SceneManager.hpp"
#include "BackgroundMenuEntity.hpp"
#include "PlayEntity.hpp"
#include "StopEntity.hpp"
#include "PlayerEntity.hpp"
#include "StopEntity.hpp"
#include "BulletEntity.hpp"
#include "EnnemyEntity.hpp"

namespace ecs {

    SceneManager::SceneManager() : _ecs(std::make_shared<Ecs>())
    {
        _ecs->getRenderManager()->init();

        _ecs->getEntityFactory()->addEntityConstructor(std::make_shared<entities::BackgroundMenuEntity>());
        _ecs->getEntityFactory()->addEntityConstructor(std::make_shared<entities::PlayerEntity>());
        _ecs->getEntityFactory()->addEntityConstructor(std::make_shared<entities::BulletEntity>());
        _ecs->getEntityFactory()->addEntityConstructor(std::make_shared<entities::EnnemyEntity>());
        _ecs->getEntityFactory()->addEntityConstructor(std::make_shared<entities::PlayEntity>());
        _ecs->getEntityFactory()->addEntityConstructor(std::make_shared<entities::StopEntity>());

        createMenu();
        // createGame();
        run();
    }

    void SceneManager::createMenu()
    {
        _current = std::make_shared<MenuScene>(_ecs);
    }

    void SceneManager::createGame()
    {
        _current = std::make_shared<GameScene>(_ecs);
    }

    void SceneManager::loadScene(const std::string& name)
    {
        if (name == "Game")
            createGame();
        else if (name == "Menu")
            createMenu();
        else
            std::cerr << "Unable to create scene : " << name << std::endl;
    }

    void SceneManager::run()
    {
        ecs::system::SystemResponse res;
        bool isPlaying = true;

        while (isPlaying) {
            res = _ecs->getSystemManager()->updateAll();
            if (res.getAction() != ecs::system::SystemResponse::CMD::NOACTION) {
                if (res.getAction() == ecs::system::SystemResponse::CMD::QUIT)
                    return;
                else if (res.getAction() == ecs::system::SystemResponse::CMD::LOADSCENE) {
                    loadScene(res.getParameters());
                }
                continue;
            }
            isPlaying = _ecs->getRenderManager()->eventUpdate();
        }
    }
}