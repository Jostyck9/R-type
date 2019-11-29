/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** EntityManager.cpp
*/

#include "EntityExceptions.hpp"
#include "Position.hpp"
#include "Rotation.hpp"
#include "EntityExceptions.hpp"
#include "EntityManager.hpp"
#include "ComponentExceptions.hpp"

using namespace ecs::entities;

EntityManager::EntityManager(std::shared_ptr<ecs::components::IComponentManager> componentManager) : _componentManager(componentManager)
{
    _functionsUpdate[ecs::network::ComponentType::POSITION] = &EntityManager::updatePosition;
    _functionsUpdate[ecs::network::ComponentType::ROTATION] = &EntityManager::updateRotation;
}

EntityManager::~EntityManager()
{
}

bool EntityManager::contains(const std::shared_ptr<Entity> &entity) const
{
    for (auto &it : _entities)
    {
        if (*it == *entity)
            return true;
    }
    return false;
}

bool EntityManager::contains(const Entity &entity) const
{
    for (auto &it : _entities)
    {
        if (*it == entity)
            return true;
    }
    return false;
}

std::shared_ptr<Entity> &EntityManager::getEntityByGameId(size_t id)
{
    if (id == entities::Entity::NOGAMEID)
        throw EntityExceptions("No entity found with gameid : NOGAMEID", "getEntityyByGameId");
    for (auto &it : _entities)
    {
        if (it->getInGameID() == id)
            return it;
    }
    throw EntityExceptions("No entity found with gameid : " + id, "getEntityyByGameId");
}

void EntityManager::updatePosition(const std::shared_ptr<entities::Entity> &entity, const ecs::network::PacketManager::Component toAdd)
{
    try
    {
        auto component = std::reinterpret_pointer_cast<ecs::components::Position>(_componentManager->getPhysicComponentOfSpecifiedType(entity, std::type_index(typeid(ecs::components::Position))));
        component->setPosition(std::make_pair(toAdd._position.x, toAdd._position.y));
    }
    catch (const ComponentExceptions &e)
    {
        _componentManager->addPhysicComponent(std::make_shared<ecs::components::Position>(toAdd._position.x, toAdd._position.y), entity);
    }
}

void EntityManager::updateRotation(const std::shared_ptr<entities::Entity> &entity, const ecs::network::PacketManager::Component toAdd)
{
    try
    {
        auto component = std::reinterpret_pointer_cast<ecs::components::Rotation>(_componentManager->getPhysicComponentOfSpecifiedType(entity, std::type_index(typeid(ecs::components::Rotation))));
        component->setRadAngle(toAdd._rotation.radAngle);
    }
    catch (const ComponentExceptions &e)
    {
        auto rotation = std::make_shared<ecs::components::Rotation>();

        rotation->setRadAngle(toAdd._rotation.radAngle);
        _componentManager->addPhysicComponent(rotation, entity);
    }
}

std::shared_ptr<Entity> EntityManager::updateEntity(const ecs::network::PacketManager::Entity &toUpdate)
{
    auto entity = getEntityByGameId(toUpdate.id);

    for (int i = 0; i < toUpdate.nbrComponents; i++)
    {
        if (_functionsUpdate.find(toUpdate.components[i].type) != _functionsUpdate.end())
        {
            (this->*(_functionsUpdate[toUpdate.components[i].type]))(entity, toUpdate.components[i]);
        }
    }
    return entity;
}

const std::shared_ptr<Entity> &EntityManager::getEntityById(size_t idEntity) const
{
    for (auto &it : _entities)
    {
        if (it->getID() == idEntity)
            return it;
    }
    throw EntityExceptions("No entity found with this id : " + idEntity, "getEntityById");
}

const std::vector<std::shared_ptr<Entity>> &EntityManager::getAllEntities() const
{
    return (_entities);
}

void EntityManager::addEntity(std::shared_ptr<Entity> entity)
{
    if (contains(entity))
        return;
    _entities.push_back(entity);
}

void EntityManager::deleteEntity(size_t idEntity)
{
    for (auto it = _entities.begin(); it != _entities.end(); it++)
    {
        if ((*it)->getID() == idEntity)
        {
            _entities.erase(it);
            _componentManager->deleteComponents(idEntity);
            return;
        }
    }
}

void EntityManager::deleteEntity(const std::shared_ptr<Entity> &entity)
{
    deleteEntity(entity->getID());
}

void EntityManager::deleteAll()
{
    _entities.clear();
    _componentManager->deleteAllComponents();
}
