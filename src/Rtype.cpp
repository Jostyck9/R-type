//
// Created by romane on 25/11/2019.
//

#include <EntityConstructor/TestPlayerEntity/TestPlayerEntity.hpp>
#include "SystemManager.hpp"
#include "EntityFactory.hpp"
#include "Rtype.hpp"

Rtype::Rtype()
{
    _managerWrapper = std::make_shared<ecs::ManagerWrapper>();
    _systemManager = std::make_shared<SystemManager>(_managerWrapper);
    _entityFactory = std::make_shared<EntityFactory>(_managerWrapper->getEntityManager(), _managerWrapper->getComponentManager());
}

void Rtype::start()
{
    _sceneManager = std::make_shared<SceneManager>();
}

void Rtype::stop()
{
    _managerWrapper->getRenderManager()->terminate();
}