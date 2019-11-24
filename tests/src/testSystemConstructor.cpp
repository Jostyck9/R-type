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

using namespace ecs::components;
using namespace ecs::entities;
using namespace ecs::system;

Test(SystemConstructor, Factory)
{
    std::list <int>idToDel;
    std::shared_ptr<IComponentManager> compoManager = std::make_shared<ComponentManager>();
    std::shared_ptr<IEntityManager> entityManager = std::make_shared<EntityManager>(compoManager);
    std::shared_ptr<ISystemManager> systemManager = std::make_shared<SystemManager>(entityManager, compoManager);
    std::shared_ptr<ISystemFactory> systemFactory = std::make_shared<SystemFactory>(entityManager, systemManager, compoManager);

    cr_assert_eq(systemFactory->isExisting("Display"), false);
    systemFactory->addSystemConstructor(std::make_shared<testSystem>());
    cr_assert_eq(systemFactory->isExisting("Display"), true);
    cr_assert_eq(systemFactory->isExisting("test"), false);
    auto res = systemFactory->createSystem("Display");
}