/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** ComponentManager.hpp
*/

#include "ComponentManager.hpp"

namespace ecs::components
{
    
ComponentManager::ComponentManager()
{
}

ComponentManager::~ComponentManager()
{
}

std::list<std::shared_ptr<IComponent>> ComponentManager::extractComponentsFrom(std::multimap<size_t, std::shared_ptr<IComponent>> &map, size_t idEntity)
{
    std::list<std::shared_ptr<IComponent>> res;

    std::pair<MMAPIterator, MMAPIterator> result = map.equal_range(idEntity);
    for (MMAPIterator it = result.first; it != result.second; it++)
        res.push_back(std::shared_ptr<IComponent>(it->second));
    return res;
}

std::shared_ptr<IComponent> ComponentManager::extractComponentsOfType(std::multimap<size_t, std::shared_ptr<IComponent>> &map, size_t idEntity, const std::type_index type)
{
    std::shared_ptr<IComponent> res;

    std::pair<MMAPIterator, MMAPIterator> result = map.equal_range(idEntity);
    for (MMAPIterator it = result.first; it != result.second; it++)
        if (type == it->second->getType()) {
            res = (std::shared_ptr<IComponent>(it->second));
            return res;
        }
    return nullptr;
}

std::list<std::shared_ptr<IComponent>> ComponentManager::getPhysicComponents(size_t idEntity)
{
    return extractComponentsFrom(_physic, idEntity);
}

std::shared_ptr<IComponent> ComponentManager::getPhysicComponentOfSpecifiedType(size_t idEntity, const std::type_index &type)
{
    return extractComponentsOfType(_physic, idEntity, type);
}

std::list<std::shared_ptr<IComponent>> ComponentManager::getPhysicComponents(const std::shared_ptr<entities::Entity> &entity)
{
    return getPhysicComponents(entity->getID());
}

std::shared_ptr<IComponent> ComponentManager::getPhysicComponentOfSpecifiedType(const std::shared_ptr<entities::Entity> &entity, const std::type_index &type)
{
    return getPhysicComponentOfSpecifiedType(entity->getID(), type);
}

std::list<std::shared_ptr<IComponent>> ComponentManager::getDisplayComponents(size_t idEntity)
{
    return extractComponentsFrom(_display, idEntity);
}

std::shared_ptr<IComponent> ComponentManager::getDisplayComponentOfSpecifiedType(size_t idEntity, const std::type_index &type)
{
    return extractComponentsOfType(_display, idEntity, type);
}

std::list<std::shared_ptr<IComponent>> ComponentManager::getDisplayComponents(const std::shared_ptr<entities::Entity> &entity)
{
    return getDisplayComponents(entity->getID());
}

std::shared_ptr<IComponent> ComponentManager::getDisplayComponentOfSpecifiedType(const std::shared_ptr<entities::Entity> &entity, const std::type_index &type)
{
    return getDisplayComponentOfSpecifiedType(entity->getID(), type);
}

std::list<std::shared_ptr<IComponent>> ComponentManager::getIOComponents(size_t idEntity)
{
    return extractComponentsFrom(_io, idEntity);
}

std::shared_ptr<IComponent> ComponentManager::getIOComponentOfSpecifiedType(size_t idEntity, const std::type_index &type)
{
    return extractComponentsOfType(_io, idEntity, type);
}

std::list<std::shared_ptr<IComponent>> ComponentManager::getIOComponents(const std::shared_ptr<entities::Entity> &entity)
{
    return getIOComponents(entity->getID());
}

std::shared_ptr<IComponent> ComponentManager::getIOComponentOfSpecifiedType(const std::shared_ptr<entities::Entity> &entity, const std::type_index &type)
{
    return getIOComponentOfSpecifiedType(entity->getID(), type);
}

std::list<std::shared_ptr<IComponent>> ComponentManager::getGameLogicComponents(size_t idEntity)
{
    return extractComponentsFrom(_gameLogic, idEntity);
}

std::shared_ptr<IComponent> ComponentManager::getGameLogicComponentOfSpecifiedType(size_t idEntity, const std::type_index &type)
{
    return extractComponentsOfType(_gameLogic, idEntity, type);
}

std::list<std::shared_ptr<IComponent>> ComponentManager::getGameLogicComponents(const std::shared_ptr<entities::Entity> &entity)
{
    return getGameLogicComponents(entity->getID());
}

std::shared_ptr<IComponent> ComponentManager::getGameLogicComponentOfSpecifiedType(const std::shared_ptr<entities::Entity> &entity, const std::type_index &type)
{
    return getGameLogicComponentOfSpecifiedType(entity->getID(), type);
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

void ComponentManager::deleteComponents(size_t idEntity)
{
    _physic.erase(idEntity);
    _display.erase(idEntity);
    _io.erase(idEntity);
    _gameLogic.erase(idEntity);
}

void ComponentManager::deleteComponents(const std::shared_ptr<entities::Entity> &entity)
{
    deleteComponents(entity->getID());
}

void ComponentManager::deleteAllComponents()
{
    _physic.clear();
    _display.clear();
    _io.clear();
    _gameLogic.clear();
}

}