//
// Created by romane on 25/11/2019.
//

#include "MovementSystem.hpp"
#include "SystemManager.hpp"
#include "DisplaySystem.hpp"
#include "Factories/EntityFactory.hpp"
#include "SFMLRenderManager.hpp"
#include "Rtype.hpp"
#include "TestPlayerEntity.hpp"

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

    _systemManager->addSystem(std::make_shared<MovementSystem>(_managerWrapper, _systemManager->getEntitiesToDelete()));
    _systemManager->addSystem(std::make_shared<DisplaySystem>(_managerWrapper, _systemManager->getEntitiesToDelete()));
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