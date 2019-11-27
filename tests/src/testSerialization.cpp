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
        cr_assert_eq(it->id, 2);
        for (auto it2 = it->components.begin(); it2 != it->components.end(); it2++)
        {
            if (it2 == it->components.begin())
            {
                cr_assert_eq(it2->type, ecs::network::POSITION);
                cr_assert_eq(it2->_position.x, 0);
                cr_assert_eq(it2->_position.y, 0);
            }
            else
            {
                cr_assert_eq(it2->type, ecs::network::ROTATION);
                cr_assert_eq(it2->_rotation.radAngle, 0);
            }
        }
    }
}