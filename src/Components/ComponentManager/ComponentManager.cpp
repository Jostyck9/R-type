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

std::list<std::reference_wrapper<std::shared_ptr<IComponent>>> ComponentManager::getPhysicComponent(const std::shared_ptr<entities::Entity> &entity)
{
    return getPhysicComponent(entity->getID());
}

std::list<std::reference_wrapper<std::shared_ptr<IComponent>>> ComponentManager::getDisplayComponent(size_t idEntity)
{
    return extractComponentsFrom(_display, idEntity);
}

std::list<std::reference_wrapper<std::shared_ptr<IComponent>>> ComponentManager::getDisplayComponent(const std::shared_ptr<entities::Entity> &entity)
{
    return getDisplayComponent(entity->getID());
}

std::list<std::reference_wrapper<std::shared_ptr<IComponent>>> ComponentManager::getIOComponent(size_t idEntity)
{
    return extractComponentsFrom(_io, idEntity);
}

std::list<std::reference_wrapper<std::shared_ptr<IComponent>>> ComponentManager::getIOComponent(const std::shared_ptr<entities::Entity> &entity)
{
    return getIOComponent(entity->getID());
}

std::list<std::reference_wrapper<std::shared_ptr<IComponent>>> ComponentManager::getGameLogicComponent(size_t idEntity)
{
    return extractComponentsFrom(_gameLogic, idEntity);
}

std::list<std::reference_wrapper<std::shared_ptr<IComponent>>> ComponentManager::getGameLogicComponent(const std::shared_ptr<entities::Entity> &entity)
{
    return getGameLogicComponent(entity->getID());
}

void ComponentManager::addPhysicComponent(std::shared_ptr<IComponent> component, size_t idEntity)
{
    _physic.insert(std::make_pair(idEntity, component));
}

void ComponentManager::addPhysicComponent(std::shared_ptr<IComponent> component, const std::shared_ptr<entities::Entity> &entity)
{
    addPhysicComponent(component, entity->getID());
}

void ComponentManager::addDisplayComponent(std::shared_ptr<IComponent> component, size_t idEntity)
{
    _display.insert(std::make_pair(idEntity, component));
}

void ComponentManager::addDisplayComponent(std::shared_ptr<IComponent> component, const std::shared_ptr<entities::Entity> &entity)
{
    addDisplayComponent(component, entity->getID());
}

void ComponentManager::addIOComponent(std::shared_ptr<IComponent> component, size_t idEntity)
{
    _io.insert(std::make_pair(idEntity, component));
}

void ComponentManager::addIOComponent(std::shared_ptr<IComponent> component, const std::shared_ptr<entities::Entity> &entity)
{
    addIOComponent(component, entity->getID());
}

void ComponentManager::addGameLogicComponent(std::shared_ptr<IComponent> component, size_t idEntity)
{
    _gameLogic.insert(std::make_pair(idEntity, component));
}

void ComponentManager::addGameLogicComponent(std::shared_ptr<IComponent> component, const std::shared_ptr<entities::Entity> &entity)
{
    addGameLogicComponent(component, entity->getID());
}

void ComponentManager::removeComponent(size_t idEntity)
{
    _physic.erase(idEntity);
    _display.erase(idEntity);
    _io.erase(idEntity);
    _gameLogic.erase(idEntity);
}

}