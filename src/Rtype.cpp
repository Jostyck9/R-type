//
// Created by romane on 25/11/2019.
//

#include <SystemManager/SystemManager.hpp>
#include <Factories/EntityFactory.hpp>
#include <SFMLRenderManager.hpp>
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

    _managerWrapper->getRenderManager()->init();
    while (isPlaying) {
        isPlaying = _managerWrapper->getRenderManager()->eventUpdate();
        _managerWrapper->getRenderManager()->graphicsUpdate();
    }
}

void Rtype::stop()
{
    _managerWrapper->getRenderManager()->terminate();
}