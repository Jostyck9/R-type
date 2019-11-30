/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** testEntityConstructor.cpp
*/

#include <memory>
#include <criterion/criterion.h>
#include "DisplaySystem.hpp"
#include "EntityFactory.hpp"
#include "EntityManager.hpp"
#include "ComponentManager.hpp"
#include "SystemManager.hpp"
#include "SystemFactory.hpp"
#include "testSystem.hpp"
#include "DisplaySystem.hpp"
#include "ManagerWrapper.hpp"

using namespace ecs::components;
using namespace ecs::entities;
using namespace ecs::system;

Test(SystemConstructor, Factory)
{
    std::shared_ptr<ecs::ManagerWrapper> managers = std::make_shared<ecs::ManagerWrapper>();
    std::list <int>idToDel;
    std::shared_ptr<ecs::entities::IEntityFactory> entityFactory = std::make_shared<ecs::entities::EntityFactory>(managers->getEntityManager(), managers->getComponentManager());
    std::shared_ptr<ISystemManager> systemManager = std::make_shared<SystemManager>(managers);
    std::shared_ptr<ISystemFactory> systemFactory = std::make_shared<SystemFactory>(managers, entityFactory, systemManager);

    cr_assert_eq(systemFactory->isExisting("Display"), false);
    systemFactory->addSystemConstructor(std::make_shared<testSystem>());
    cr_assert_eq(systemFactory->isExisting("Display"), true);
    cr_assert_eq(systemFactory->isExisting("test"), false);
    auto res = systemFactory->createSystem("Display");
    cr_assert_eq(systemFactory->isExisting("Display"), true);
    systemFactory->remove("Display");
    cr_assert_eq(systemFactory->isExisting("Display"), false);
}

Test(SystemConstructor, DeleteAll)
{
    std::shared_ptr<ecs::ManagerWrapper> managers = std::make_shared<ecs::ManagerWrapper>();
    std::list <int>idToDel;
    std::shared_ptr<ecs::entities::IEntityFactory> entityFactory = std::make_shared<ecs::entities::EntityFactory>(managers->getEntityManager(), managers->getComponentManager());
    std::shared_ptr<ISystemManager> systemManager = std::make_shared<SystemManager>(managers);
    std::shared_ptr<ISystemFactory> systemFactory = std::make_shared<SystemFactory>(managers, entityFactory, systemManager);

    systemFactory->addSystemConstructor(std::make_shared<testSystem>());
    cr_assert_eq(systemFactory->isExisting("Display"), true);
    systemFactory->deleteAll();
    cr_assert_eq(systemFactory->isExisting("Display"), false);
}