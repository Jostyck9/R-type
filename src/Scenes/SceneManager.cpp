//Input
// Created by romane on 28/11/2019.
//

#include <iostream>
#include <EntityConstructor/NameRoomEntity/NameRoomEntity.hpp>
#include <EntityConstructor/NumberPlayersEntity/NumberPlayersEntity.hpp>
#include <EntityConstructor/BackgroundWithoutTitleEntity/BackgroundWithoutTitleEntity.hpp>
#include <EntityConstructor/BackEntity/BackEntity.hpp>
#include "SystemResponse.hpp"
#include "MenuScene.hpp"
#include "GameScene.hpp"
#include "SceneManager.hpp"
#include "BackgroundMenuEntity.hpp"
#include "GameBackgroundEntity.hpp"
#include "PlayEntity.hpp"
#include "StopEntity.hpp"
#include "PlayerEntity.hpp"
#include "BulletEntity.hpp"
#include "EnnemyEntity.hpp"
#include "ChooseRoomScene.hpp"
#include "EnnemyType01Entity.hpp"
#include "PlanetEntity.hpp"
#include "PlanetRingEntity.hpp"
#include "StarsEntity.hpp"

namespace ecs {

    SceneManager::SceneManager() : _ecs(std::make_shared<Ecs>())
    {
        _ecs->getRenderManager()->init();
        _ecs->getEntityFactory()->addEntityConstructor(std::make_shared<entities::BackgroundMenuEntity>());
        _ecs->getEntityFactory()->addEntityConstructor(std::make_shared<entities::BackgroundWithoutTitleEntity>());
        _ecs->getEntityFactory()->addEntityConstructor(std::make_shared<entities::BackEntity>());
        _ecs->getEntityFactory()->addEntityConstructor(std::make_shared<entities::GameBackgroundEntity>());
        _ecs->getEntityFactory()->addEntityConstructor(std::make_shared<entities::PlanetEntity>());
        _ecs->getEntityFactory()->addEntityConstructor(std::make_shared<entities::PlanetRingEntity>());
        _ecs->getEntityFactory()->addEntityConstructor(std::make_shared<entities::StarsEntity>());
        _ecs->getEntityFactory()->addEntityConstructor(std::make_shared<entities::PlayerEntity>());
        _ecs->getEntityFactory()->addEntityConstructor(std::make_shared<entities::BulletEntity>());
        _ecs->getEntityFactory()->addEntityConstructor(std::make_shared<entities::EnnemyEntity>());
        _ecs->getEntityFactory()->addEntityConstructor(std::make_shared<entities::EnnemyType01Entity>());
        _ecs->getEntityFactory()->addEntityConstructor(std::make_shared<entities::PlayEntity>());
        _ecs->getEntityFactory()->addEntityConstructor(std::make_shared<entities::StopEntity>());
        _ecs->getEntityFactory()->addEntityConstructor(std::make_shared<entities::NameRoomEntity>());
        _ecs->getEntityFactory()->addEntityConstructor(std::make_shared<entities::NumberPlayersEntity>());

        createMenu();
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

    void SceneManager::createChooseRoom()
    {
        _current = std::make_shared<ChooseRoomScene>(_ecs);
    }

    void SceneManager::loadScene(const std::string& name)
    {
        if (name == "Game")
            createGame();
        else if (name == "Menu")
            createMenu();
        else if (name == "ChooseRoomSystem")
            createChooseRoom();
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
            }
            isPlaying = _ecs->getRenderManager()->eventUpdate();
        }
    }
}