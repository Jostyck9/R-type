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

    _creationFunction["test"] = &ecs::entities::EntityFactory::testEntity;
}

EntityFactory::~EntityFactory()
{
}

std::shared_ptr<Entity> EntityFactory::createEntity(const std::string &name)
{
    if (_creationFunction.find(name) == _creationFunction.end()) {
        // TODO Throw the wright exception
        throw std::exception();
    }
    return (this->*(_creationFunction[name]))();
}

std::shared_ptr<Entity> EntityFactory::testEntity()
{
    std::shared_ptr<Entity> toCreate = std::make_shared<Entity>();

    _entityManager->addEntity(toCreate);
    _componentManager->addPhysicComponent(std::make_shared<components::Position>(0, 0), toCreate);
    _componentManager->addPhysicComponent(std::make_shared<components::Velocity>(10), toCreate);
    return toCreate;
}