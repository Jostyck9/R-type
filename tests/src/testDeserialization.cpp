/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** testDeserialization.cpp
*/

#include <iostream>
#include <memory>
#include <criterion/criterion.h>
#include "PacketManager.hpp"
#include "TestEntity.hpp"
#include "EntityFactory.hpp"
#include "EntityManager.hpp"
#include "ComponentManager.hpp"
#include "Rotation.hpp"
#include "Position.hpp"

using namespace ecs::components;
using namespace ecs::entities;

Test(Deserialization, CreateEntity)
{
    std::shared_ptr<IComponentManager> compoManager = std::make_shared<ComponentManager>();
    std::shared_ptr<IEntityManager> entityManager = std::make_shared<EntityManager>(compoManager);
    std::shared_ptr<IEntityFactory> entityFactory = std::make_shared<EntityFactory>(entityManager, compoManager);

    ecs::network::PacketManager::Entity toCreate;
    ecs::network::PacketManager::Component toAdd;
    ecs::network::PacketManager::Component toAdd2;

    toAdd.type = ecs::network::POSITION;
    toAdd._position.x = 20;
    toAdd._position.y = 30;
    toAdd2.type = ecs::network::ROTATION;
    toAdd2._rotation.radAngle = 20; 
    toCreate.id = 4;
    toCreate.nbrComponents = 2;
    toCreate.components[0] = toAdd;
    toCreate.components[1] = toAdd2;

    entityFactory->createEntity(toCreate);
    auto entities = entityManager->getAllEntities();
    cr_assert_eq(entities.size(), 1);
    cr_assert_eq(compoManager->getPhysicComponents(entities[0]).size(), 2);
    auto position = std::reinterpret_pointer_cast<Position>(compoManager->getPhysicComponentOfSpecifiedType(entities[0], std::type_index(typeid(Position))));
    cr_assert_eq(toAdd._position.x, position->getX());
    cr_assert_eq(toAdd._position.y, position->getY());

    auto rotation = std::reinterpret_pointer_cast<Rotation>(compoManager->getPhysicComponentOfSpecifiedType(entities[0], std::type_index(typeid(Rotation))));
    cr_assert_eq(toAdd2._rotation.radAngle, rotation->getRadAngle());
}

Test(Deserialization, UpdateEntiy)
{
    std::shared_ptr<IComponentManager> compoManager = std::make_shared<ComponentManager>();
    std::shared_ptr<IEntityManager> entityManager = std::make_shared<EntityManager>(compoManager);
    std::shared_ptr<IEntityFactory> entityFactory = std::make_shared<EntityFactory>(entityManager, compoManager);

    ecs::network::PacketManager::Entity toCreate;
    ecs::network::PacketManager::Component toAdd;
    ecs::network::PacketManager::Component toAdd2;

    toAdd.type = ecs::network::POSITION;
    toAdd._position.x = 20; 
    toAdd._position.y = 30;
    toAdd2.type = ecs::network::ROTATION;
    toAdd2._rotation.radAngle = 20; 
    toCreate.id = 4;
    toCreate.nbrComponents = 2;
    toCreate.components[0] = toAdd;
    toCreate.components[1] = toAdd2;

    entityFactory->createEntity(toCreate);

    toAdd._position.x = 40;
    toAdd._position.y = 50;
    toAdd2._rotation.radAngle = 10;
    toCreate.nbrComponents = 2;
    toCreate.components[0] = toAdd;
    toCreate.components[1] = toAdd2;

    entityFactory->createEntity(toCreate);

    auto entities = entityManager->getAllEntities();
    cr_assert_eq(entities.size(), 1);
    cr_assert_eq(compoManager->getPhysicComponents(entities[0]).size(), 2);
    auto position = std::reinterpret_pointer_cast<Position>(compoManager->getPhysicComponentOfSpecifiedType(entities[0], std::type_index(typeid(Position))));
    cr_assert_eq(toAdd._position.x, position->getX());
    cr_assert_eq(toAdd._position.y, position->getY());

    auto rotation = std::reinterpret_pointer_cast<Rotation>(compoManager->getPhysicComponentOfSpecifiedType(entities[0], std::type_index(typeid(Rotation))));
    cr_assert_eq(toAdd2._rotation.radAngle, rotation->getRadAngle());
}

Test(Deserialization, UpdateEntiyWithMissingComponent)
{
    std::shared_ptr<IComponentManager> compoManager = std::make_shared<ComponentManager>();
    std::shared_ptr<IEntityManager> entityManager = std::make_shared<EntityManager>(compoManager);
    std::shared_ptr<IEntityFactory> entityFactory = std::make_shared<EntityFactory>(entityManager, compoManager);

    ecs::network::PacketManager::Entity toCreate;
    ecs::network::PacketManager::Component toAdd;
    ecs::network::PacketManager::Component toAdd2;

    toAdd.type = ecs::network::POSITION;
    toAdd._position.x = 20; 
    toAdd._position.y = 30;
    toAdd2.type = ecs::network::ROTATION;
    toAdd2._rotation.radAngle = 20; 
    toCreate.id = 4;
    toCreate.nbrComponents = 1;
    toCreate.components[0] = toAdd;

    entityFactory->createEntity(toCreate);

    toAdd._position.x = 40;
    toAdd._position.y = 50;
    toAdd2._rotation.radAngle = 10;

    toCreate.nbrComponents = 2;
    toCreate.components[0] = toAdd;
    toCreate.components[1] = toAdd2;

    entityFactory->createEntity(toCreate);

    auto entities = entityManager->getAllEntities();
    cr_assert_eq(entities.size(), 1);
    cr_assert_eq(compoManager->getPhysicComponents(entities[0]).size(), 2);
    auto position = std::reinterpret_pointer_cast<Position>(compoManager->getPhysicComponentOfSpecifiedType(entities[0], std::type_index(typeid(Position))));
    cr_assert_eq(toAdd._position.x, position->getX());
    cr_assert_eq(toAdd._position.y, position->getY());

    auto rotation = std::reinterpret_pointer_cast<Rotation>(compoManager->getPhysicComponentOfSpecifiedType(entities[0], std::type_index(typeid(Rotation))));
    cr_assert_eq(toAdd2._rotation.radAngle, rotation->getRadAngle());
}