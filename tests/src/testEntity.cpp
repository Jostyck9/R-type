/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** test.cpp
*/

#include <memory>
#include <criterion/criterion.h>
#include "Entities/Entity.hpp"

Test(Entity, entity_compared)
{
    std::unique_ptr<entities::Entity> toTest = std::make_unique<entities::Entity>();
    std::unique_ptr<entities::Entity> toTest2 = std::make_unique<entities::Entity>();

    cr_assert_eq(true, (*toTest == *toTest));
    cr_assert_eq(false, (*toTest == *toTest2));
}