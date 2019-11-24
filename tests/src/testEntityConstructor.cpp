/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** testEntityConstructor.cpp
*/

#include <memory>
#include <criterion/criterion.h>
#include "TestEntity.hpp"
#include "EntityFactory.hpp"
#include "EntityManager.hpp"
#include "ComponentManager.hpp"
#include "Position.hpp"
#include "Velocity.hpp"

using namespace ecs::components;
using namespace ecs::entities;

Test(EntityConstructor, TestEntity)
{
    std::shared_ptr<IComponentManager> compoManager = std::make_shared<ComponentManager>();
    std::shared_ptr<IEntityManager> entityManager = std::make_shared<EntityManager>(compoManager);
    std::shared_ptr<IEntityConstructor> entityConstr = std::make_shared<TestEntity>();

    cr_assert_eq(entityConstr->getName(), "Test");
    auto res = entityConstr->create(entityManager, compoManager);

    auto pos = compoManager->getPhysicComponents(res);
    cr_assert_eq(pos.size(), 3);
    cr_assert_none_throw(compoManager->getPhysicComponentOfSpecifiedType(res, std::type_index(typeid(Position))));
    cr_assert_none_throw(compoManager->getPhysicComponentOfSpecifiedType(res, std::type_index(typeid(Velocity))));
}

Test(EntityConstructor, Factory)
{
    std::shared_ptr<IComponentManager> compoManager = std::make_shared<ComponentManager>();
    std::shared_ptr<IEntityManager> entityManager = std::make_shared<EntityManager>(compoManager);
    std::shared_ptr<IEntityFactory> entityFactory = std::make_shared<EntityFactory>(entityManager, compoManager);
    entityFactory->addEntityConstructor(std::make_shared<TestEntity>());

    auto res = entityFactory->createEntity("Test");

    auto pos = compoManager->getPhysicComponents(res);
    cr_assert_eq(pos.size(), 3);
    cr_assert_none_throw(compoManager->getPhysicComponentOfSpecifiedType(res, std::type_index(typeid(Position))));
    cr_assert_none_throw(compoManager->getPhysicComponentOfSpecifiedType(res, std::type_index(typeid(Velocity))));
}