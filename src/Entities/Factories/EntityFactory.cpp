/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** EntityFactory.cpp
*/

#include "Physics/Position.hpp"
#include "Physics/Velocity.hpp"
#include "EntityFactory.hpp"
#include "EntityExceptions.hpp"

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