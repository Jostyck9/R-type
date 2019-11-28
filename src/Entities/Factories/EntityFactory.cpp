/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** EntityFactory.cpp
*/

#include <iostream>
#include "Position.hpp"
#include "Velocity.hpp"
#include "Rotation.hpp"
#include "EntityFactory.hpp"
#include "EntityExceptions.hpp"

using namespace ecs::entities;

EntityFactory::EntityFactory(std::shared_ptr<IEntityManager> entityManager, std::shared_ptr<ecs::components::IComponentManager> componentsManager)
{
    _entityManager = entityManager;
    _componentManager = componentsManager;

    _functionsUpdate[ecs::network::ComponentType::POSITION] = &EntityFactory::addPosition;
    _functionsUpdate[ecs::network::ComponentType::ROTATION] = &EntityFactory::addRotation;
}

EntityFactory::~EntityFactory()
{
}

void EntityFactory::addPosition(std::shared_ptr<ecs::entities::Entity> &entity, const ecs::network::Component data)
{
    _componentManager->addPhysicComponent(std::make_shared<ecs::components::Position>(data._position.x, data._position.y), entity);
}

void EntityFactory::addRotation(std::shared_ptr<ecs::entities::Entity> &entity, const ecs::network::Component data)
{
    auto rotation = std::make_shared<ecs::components::Rotation>();

    rotation->setRadAngle(data._rotation.radAngle);
    _componentManager->addPhysicComponent(rotation, entity);
}

bool EntityFactory::isExisting(const std::string &name)
{
    if (_creationFunction.find(name) == _creationFunction.end())
    {
        return false;
    }
    return true;
}

std::shared_ptr<ecs::entities::Entity> EntityFactory::updateIfExisting(const ecs::network::Entity &entity)
{
    return _entityManager->updateEntity(entity);
}

void EntityFactory::addEntityConstructor(std::shared_ptr<IEntityConstructor> constructor)
{
    if (isExisting(constructor->getName()))
    {
        throw EntityExceptions("Error: Could not add Entity Constructor ", std::string(__FILE__) + ' ' + std::to_string(__LINE__));
    }
    _creationFunction[constructor->getName()] = constructor;
}

std::shared_ptr<Entity> EntityFactory::createEntity(const std::string &name)
{
    if (!isExisting(name))
    {
        throw EntityExceptions("Error: Could not add Entity \'" + name + '\'', std::string(__FILE__) + ' ' + std::to_string(__LINE__));
    }
    return (_creationFunction[name])->create(_entityManager, _componentManager);
}

std::shared_ptr<Entity> EntityFactory::createEntity(ecs::network::Entity &entity)
{
    if (entity.id != Entity::NOGAMEID)
    {
        try
        {
            return updateIfExisting(entity);
        }
        catch (const EntityExceptions &e)
        {
        }

        auto newEntity = std::make_shared<ecs::entities::Entity>(static_cast<ecs::entities::Entity::option>(entity.id));
        for (auto it : entity.components) {
            if (_functionsUpdate.find(it.type) == _functionsUpdate.end())
                continue;
            (this->*(_functionsUpdate[it.type]))(newEntity, it);
        }
        _entityManager->addEntity(newEntity);
        return newEntity;
    }
    throw EntityExceptions("Cannot create an entity with id : NOGAMEID", "EntityFactory::createEntity");
}