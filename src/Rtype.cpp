//
// Created by romane on 25/11/2019.
//

#include <EntityConstructor/TestPlayerEntity/TestPlayerEntity.hpp>
#include "StopEntity.hpp"
#include "PlayEntity.hpp"
#include "SystemManager.hpp"
#include "DisplaySystem.hpp"
#include "EntityFactory.hpp"
#include "Rtype.hpp"

Rtype::Rtype()
{
    _managerWrapper = std::make_shared<ecs::ManagerWrapper>();
    _systemManager = std::make_shared<SystemManager>(_managerWrapper);
    _entityFactory = std::make_shared<EntityFactory>(_managerWrapper->getEntityManager(), _managerWrapper->getComponentManager());
}

Rtype::~Rtype()
{

}

void Rtype::start()
{
    bool isPlaying = true;

    _systemManager->addSystem(std::make_shared<DisplaySystem>(_managerWrapper, _systemManager->getEntitiesToDelete()));
    _entityFactory->addEntityConstructor(std::make_shared<PlayEntity>());
    _entityFactory->createEntity("Play");
    _entityFactory->addEntityConstructor(std::make_shared<StopEntity>());
    _entityFactory->createEntity("Stop");
    _entityFactory->addEntityConstructor(std::make_shared<TestPlayerEntity>());
    _entityFactory->createEntity("TestPlayer");
    _managerWrapper->getRenderManager()->init();
    while (isPlaying) {
        _systemManager->updateAll();
        isPlaying = _managerWrapper->getRenderManager()->eventUpdate();
    }
}

void Rtype::stop()
{
    _managerWrapper->getRenderManager()->terminate();
}