//
// Created by romane on 25/11/2019.
//

#include <SystemManager/SystemManager.hpp>
#include <Factories/EntityFactory.hpp>
#include <SFMLRenderManager.hpp>
#include "Rtype.hpp"

Rtype::Rtype()
{
    _componentManager = std::make_shared<ComponentManager>();
    _entityManager = std::make_shared<EntityManager>(_componentManager);
    _systemManager = std::make_shared<SystemManager>(_entityManager, _componentManager);
    _entityFactory = std::make_shared<EntityFactory>(_entityManager, _componentManager);
    _renderManager = std::make_shared<SFMLRenderManager>();
}

Rtype::~Rtype()
{

}

void Rtype::start()
{
    bool isPlaying = true;

    _renderManager->init();
    while (isPlaying) {
        isPlaying = _renderManager->eventUpdate();
    }
}

void Rtype::stop()
{
    _renderManager->terminate();
}