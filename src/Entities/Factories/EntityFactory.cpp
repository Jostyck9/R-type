/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** EntityFactory.cpp
*/

#include "Physics/Position.hpp"
#include "Physics/Velocity.hpp"
#include "EntityFactory.hpp"

using namespace ecs::entities;

EntityFactory::EntityFactory(std::shared_ptr<IEntityManager> entityManager, std::shared_ptr<components::IComponentManager> componentsManager)
{
    _entityManager = entityManager;
    _componentManager = componentsManager;
}

EntityFactory::~EntityFactory()
{
}

bool EntityFactory::isExisting(const std::string &name)
{
    if (_creationFunction.find(name) == _creationFunction.end())
    {
        return false;
    }
    return true;
}

void EntityFactory::addEntityConstructor(std::shared_ptr<IEntityConstructor> constructor)
{
    if (isExisting(constructor->getName()))
    {
        // TODO Throw the wright exception
        throw std::exception();
    }
    _creationFunction[constructor->getName()] = constructor;
}

std::shared_ptr<Entity> EntityFactory::createEntity(const std::string &name)
{
    if (!isExisting(name))
    {
        // TODO Throw the wright exception
        throw std::exception();
    }
    return (_creationFunction[name])->create(_entityManager, _componentManager);
}