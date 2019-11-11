/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** ComponentManager.hpp
*/

#include "ComponentManager.hpp"

namespace components
{
    
ComponentManager::ComponentManager()
{
}

ComponentManager::~ComponentManager()
{
}

std::list<std::reference_wrapper<std::shared_ptr<IComponent>>> ComponentManager::extractComponentsFrom(std::multimap<size_t, std::shared_ptr<IComponent>> &map, size_t idEntity)
{
    std::list<std::reference_wrapper<std::shared_ptr<IComponent>>> res;

    std::pair<MMAPIterator, MMAPIterator> result = map.equal_range(idEntity);
    for (MMAPIterator it = result.first; it != result.second; it++)
        res.push_back(std::reference_wrapper<std::shared_ptr<IComponent>>(it->second));
    return res;
}

std::list<std::reference_wrapper<std::shared_ptr<IComponent>>> ComponentManager::getPhysicComponent(size_t idEntity)
{
    return extractComponentsFrom(_physic, idEntity);
}

std::list<std::reference_wrapper<std::shared_ptr<IComponent>>> ComponentManager::getDisplayComponent(size_t idEntity)
{
    return extractComponentsFrom(_display, idEntity);
}

std::list<std::reference_wrapper<std::shared_ptr<IComponent>>> ComponentManager::getIOComponent(size_t idEntity)
{
    return extractComponentsFrom(_io, idEntity);
}

std::list<std::reference_wrapper<std::shared_ptr<IComponent>>> ComponentManager::getNetworkComponent(size_t idEntity)
{
    return extractComponentsFrom(_network, idEntity);
}

std::list<std::reference_wrapper<std::shared_ptr<IComponent>>> ComponentManager::getGameLogicComponent(size_t idEntity)
{
    return extractComponentsFrom(_gameLogic, idEntity);
}

void ComponentManager::addPhysicComponent(std::shared_ptr<IComponent> component, size_t idEntity)
{
    _physic.insert(std::make_pair(idEntity, component));
}

void ComponentManager::addDisplayComponent(std::shared_ptr<IComponent> component, size_t idEntity)
{
    _display.insert(std::make_pair(idEntity, component));
}

void ComponentManager::addIOComponent(std::shared_ptr<IComponent> component, size_t idEntity)
{
    _io.insert(std::make_pair(idEntity, component));
}

void ComponentManager::addNetworkComponent(std::shared_ptr<IComponent> component, size_t idEntity)
{
    _network.insert(std::make_pair(idEntity, component));
}

void ComponentManager::addGameLogicComponent(std::shared_ptr<IComponent> component, size_t idEntity)
{
    _gameLogic.insert(std::make_pair(idEntity, component));
}

void ComponentManager::removeComponent(size_t idEntity)
{
    _physic.erase(idEntity);
    _display.erase(idEntity);
    _io.erase(idEntity);
    _network.erase(idEntity);
    _gameLogic.erase(idEntity);
}

}