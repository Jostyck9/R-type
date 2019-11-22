/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** testEntityConstructor.cpp
*/

#include <memory>
#include <criterion/criterion.h>
#include "TestEntity.hpp"
#include "EntityManager.hpp"
#include "ComponentManager.hpp"

Test(EntityConstructor, TestEntity)
{
    // std::shared_ptr<ecs::components::
    std::shared_ptr<ecs::entities::IEntityConstructor> entityConstr = std::make_shared<ecs::entities::TestEntity>();

    cr_assert_eq(entityConstr->getName(), "Test");
}