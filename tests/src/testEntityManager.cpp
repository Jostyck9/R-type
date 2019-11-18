/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** testEntityManager.cpp
*/

#include <memory>
#include <criterion/criterion.h>
#include "Entities/IEntityManager.hpp"
#include "Entities/EntityManager.hpp"

Test(EntityManager, test_addEntity)
{
    std::unique_ptr<entities::IEntityManager> manager = std::make_unique<entities::EntityManager>();
    std::shared_ptr<entities::Entity> toTest = std::make_unique<entities::Entity>();
    std::shared_ptr<entities::Entity> toTest2 = std::make_unique<entities::Entity>();

    manager->addEntity(toTest);
    cr_assert_eq(1, manager->getAllEntities().size());
    cr_assert_eq(*toTest, (*manager->getAllEntities()[0]));

    manager->addEntity(toTest);
    cr_assert_eq(1, manager->getAllEntities().size());

    manager->addEntity(toTest2);
    cr_assert_eq(2, manager->getAllEntities().size());
}

Test(EntityManager, test_deleteEntity)
{
    std::unique_ptr<entities::IEntityManager> manager = std::make_unique<entities::EntityManager>();
    std::shared_ptr<entities::Entity> toTest = std::make_unique<entities::Entity>();

    manager->addEntity(toTest);
    manager->deleteAll();
    cr_assert_eq(0, manager->getAllEntities().size());

    manager->addEntity(toTest);
    manager->deleteEntity(toTest->getID());
    cr_assert_eq(0, manager->getAllEntities().size());

    manager->addEntity(toTest);
    manager->deleteEntity(76);
    cr_assert_eq(1, manager->getAllEntities().size());

    manager->deleteEntity(toTest);
    cr_assert_eq(0, manager->getAllEntities().size());
}

Test(EntityManager, test_getEntity)
{
    std::unique_ptr<entities::IEntityManager> manager = std::make_unique<entities::EntityManager>();
    std::shared_ptr<entities::Entity> toTest = std::make_unique<entities::Entity>();

    manager->addEntity(toTest);
    cr_assert_eq(1, manager->getAllEntities().size());
    cr_assert_eq(*toTest, (*manager->getAllEntities()[0]));

    cr_assert_eq(*toTest, (*manager->getEntityById(toTest->getID())));
}