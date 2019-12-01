//
// Created by romane on 28/11/2019.
//

#include <memory>
#include <SystemConstructor/ParallaxSystem/ParallaxSystem.hpp>
#include "ButtonColorSystem.hpp"
#include "ChooseRoomSystem.hpp"
#include "ChooseRoomScene.hpp"
#include "DisplaySystem.hpp"

ecs::ChooseRoomScene::ChooseRoomScene(std::shared_ptr<Ecs> &ecs) : _ecs(ecs)
{
    _ecs->getEntityManager()->deleteAll();
    _ecs->getSystemManager()->deleteAll();

    // TODO use system Factory inside ecs
    _ecs->getSystemManager()->addSystem(std::make_shared<system::DisplaySystem>(_ecs->getManagerWrapper(), _ecs->getEntityFactory(), _ecs->getSystemManager()->getEntitiesToDelete()));
    _ecs->getSystemManager()->addSystem(std::make_shared<system::ChooseRoomSystem>(_ecs->getManagerWrapper(), _ecs->getEntityFactory(), _ecs->getSystemManager()->getEntitiesToDelete()));
    _ecs->getSystemManager()->addSystem(std::make_shared<system::ButtonColorSystem>(_ecs->getManagerWrapper(), _ecs->getEntityFactory(), _ecs->getSystemManager()->getEntitiesToDelete()));
    _ecs->getSystemManager()->addSystem(std::make_shared<system::ParallaxSystem>(_ecs->getManagerWrapper(), _ecs->getEntityFactory(), _ecs->getSystemManager()->getEntitiesToDelete()));

    _ecs->getEntityFactory()->createEntity("BackgroundWithoutTitle");
    _ecs->getEntityFactory()->createEntity("Stars");
    _ecs->getEntityFactory()->createEntity("ListRoom", std::make_pair(525, 100));
    _ecs->getEntityFactory()->createEntity("NumberPlayers", std::make_pair(850, 100));
    _ecs->getEntityFactory()->createEntity("ListRoom", std::make_pair(525, 200));
    _ecs->getEntityFactory()->createEntity("NumberPlayers", std::make_pair(850, 200));
    _ecs->getEntityFactory()->createEntity("ListRoom", std::make_pair(525, 300));
    _ecs->getEntityFactory()->createEntity("NumberPlayers", std::make_pair(850, 300));
    _ecs->getEntityFactory()->createEntity("ListRoom", std::make_pair(525, 400));
    _ecs->getEntityFactory()->createEntity("NumberPlayers", std::make_pair(850, 400));
    _ecs->getEntityFactory()->createEntity("ListRoom", std::make_pair(525, 500));
    _ecs->getEntityFactory()->createEntity("NumberPlayers", std::make_pair(850, 500));
    _ecs->getEntityFactory()->createEntity("ListRoom", std::make_pair(525, 600));
    _ecs->getEntityFactory()->createEntity("NumberPlayers", std::make_pair(850, 600));
    _ecs->getEntityFactory()->createEntity("ListRoom", std::make_pair(525, 700));
    _ecs->getEntityFactory()->createEntity("NumberPlayers", std::make_pair(850, 700));
    _ecs->getEntityFactory()->createEntity("ListRoom", std::make_pair(525, 800));
    _ecs->getEntityFactory()->createEntity("NumberPlayers", std::make_pair(850, 800));
    _ecs->getEntityFactory()->createEntity("Back");
}