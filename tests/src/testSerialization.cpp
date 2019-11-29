/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** testSerialization.cpp
*/

#include <memory>
#include <criterion/criterion.h>
#include "TestEntity.hpp"
#include "EntityFactory.hpp"
#include "EntityManager.hpp"
#include "ComponentManager.hpp"
#include "Position.hpp"
#include "Velocity.hpp"
#include "Serializer.hpp"

using namespace ecs::components;
using namespace ecs::entities;

Test(EntitySerialization, TestEntity)
{
    std::shared_ptr<IComponentManager> compoManager = std::make_shared<ComponentManager>();
    std::shared_ptr<IEntityManager> entityManager = std::make_shared<EntityManager>(compoManager);
    std::shared_ptr<IEntityFactory> entityFactory = std::make_shared<EntityFactory>(entityManager, compoManager);
    ecs::entities::Serializer seriali(entityManager, compoManager);

    entityFactory->addEntityConstructor(std::make_shared<TestEntity>());
    auto res = entityFactory->createEntity("Test");

    auto res2 = seriali.serialize();
    cr_assert_eq(res2.size(), 1);
    for (auto it = res2.begin(); it != res2.end(); it++)
    {
        cr_assert_eq(true, it->isSuccessful());
        cr_assert_eq(42, it->getMagicNumber());
        cr_assert_eq(ecs::network::PacketManager::UPDATE, it->getCmd());
        cr_assert_eq(1, it->getListEntities().size);

        cr_assert_eq(2, it->getListEntities().list[0].nbrComponents);
        cr_assert_eq(ecs::network::POSITION, it->getListEntities().list[0].components[0].type);
        cr_assert_eq(0, it->getListEntities().list[0].components[0]._position.x);
        cr_assert_eq(0, it->getListEntities().list[0].components[0]._position.y);

        cr_assert_eq(ecs::network::ROTATION, it->getListEntities().list[0].components[1].type);
        cr_assert_eq(0, it->getListEntities().list[0].components[1]._rotation.radAngle);

    }
}