/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** test.cpp
*/

#include <iostream>
#include <memory>
#include <criterion/criterion.h>
#include "IComponentManager.hpp"
#include "ComponentManager.hpp"
#include "Acceleration.hpp"

Test(ComponentManager, test_physic) {
    std::unique_ptr<ecs::components::IComponentManager> manager = std::make_unique<ecs::components::ComponentManager>();
    std::shared_ptr<ecs::components::IComponent> component = std::make_shared<ecs::components::Acceleration>();
    std::shared_ptr<entities::Entity> entity = std::make_shared<entities::Entity>();

    manager->addPhysicComponent(component, 0);
    auto res = manager->getPhysicComponents(0); 
    cr_assert(manager->getPhysicComponents(0).size() == 1);
    cr_assert(manager->getIOComponents(0).size() == 0);
    cr_assert(manager->getGameLogicComponents(0).size() == 0);
    cr_assert(manager->getDisplayComponents(0).size() == 0);
    cr_assert_eq(component->getType(), (*res.begin()).get()->getType());

    manager->removeComponents(0);
    res = manager->getPhysicComponents(0);
    cr_assert(manager->getPhysicComponents(0).size() == 0);
    cr_assert(manager->getIOComponents(0).size() == 0);
    cr_assert(manager->getGameLogicComponents(0).size() == 0);
    cr_assert(manager->getDisplayComponents(0).size() == 0);

    manager->addPhysicComponent(component, entity);
    res = manager->getPhysicComponents(entity);
    cr_assert(manager->getPhysicComponents(entity).size() == 1);
    cr_assert(manager->getIOComponents(entity).size() == 0);
    cr_assert(manager->getGameLogicComponents(entity).size() == 0);
    cr_assert(manager->getDisplayComponents(entity).size() == 0);
    cr_assert_eq(component->getType(), (*res.begin()).get()->getType());
}

Test(ComponentManager, test_display) {
    std::unique_ptr<ecs::components::IComponentManager> manager = std::make_unique<ecs::components::ComponentManager>();
    std::shared_ptr<ecs::components::IComponent> component = std::make_shared<ecs::components::Acceleration>();
    std::shared_ptr<entities::Entity> entity = std::make_shared<entities::Entity>();

    manager->addDisplayComponent(component, 0);
    auto res = manager->getDisplayComponents(0); 
    cr_assert(manager->getDisplayComponents(0).size() == 1);
    cr_assert(manager->getIOComponents(0).size() == 0);
    cr_assert(manager->getGameLogicComponents(0).size() == 0);
    cr_assert(manager->getPhysicComponents(0).size() == 0);
    cr_assert_eq(component->getType(), (*res.begin()).get()->getType());

    manager->removeComponents(0);
    res = manager->getDisplayComponents(0);
    cr_assert(manager->getDisplayComponents(0).size() == 0);
    cr_assert(manager->getIOComponents(0).size() == 0);
    cr_assert(manager->getGameLogicComponents(0).size() == 0);
    cr_assert(manager->getPhysicComponents(0).size() == 0);

    manager->addDisplayComponent(component, entity);
    res = manager->getDisplayComponents(entity);
    cr_assert(manager->getDisplayComponents(entity).size() == 1);
    cr_assert(manager->getIOComponents(entity).size() == 0);
    cr_assert(manager->getGameLogicComponents(entity).size() == 0);
    cr_assert(manager->getPhysicComponents(entity).size() == 0);
    cr_assert_eq(component->getType(), (*res.begin()).get()->getType());
}

Test(ComponentManager, test_io) {
    std::unique_ptr<ecs::components::IComponentManager> manager = std::make_unique<ecs::components::ComponentManager>();
    std::shared_ptr<ecs::components::IComponent> component = std::make_shared<ecs::components::Acceleration>();
    std::shared_ptr<entities::Entity> entity = std::make_shared<entities::Entity>();

    manager->addIOComponent(component, 0);
    auto res = manager->getIOComponents(0); 
    cr_assert(manager->getIOComponents(0).size() == 1);
    cr_assert(manager->getDisplayComponents(0).size() == 0);
    cr_assert(manager->getGameLogicComponents(0).size() == 0);
    cr_assert(manager->getPhysicComponents(0).size() == 0);
    cr_assert_eq(component->getType(), (*res.begin()).get()->getType());

    manager->removeComponents(0);
    res = manager->getIOComponents(0);
    cr_assert(manager->getIOComponents(0).size() == 0);
    cr_assert(manager->getDisplayComponents(0).size() == 0);
    cr_assert(manager->getGameLogicComponents(0).size() == 0);
    cr_assert(manager->getPhysicComponents(0).size() == 0);

    manager->addIOComponent(component, entity);
    res = manager->getIOComponents(entity);
    cr_assert(manager->getIOComponents(entity).size() == 1);
    cr_assert(manager->getDisplayComponents(entity).size() == 0);
    cr_assert(manager->getGameLogicComponents(entity).size() == 0);
    cr_assert(manager->getPhysicComponents(entity).size() == 0);
    cr_assert_eq(component->getType(), (*res.begin()).get()->getType());
}

Test(ComponentManager, test_game_logic) {
    std::unique_ptr<ecs::components::IComponentManager> manager = std::make_unique<ecs::components::ComponentManager>();
    std::shared_ptr<ecs::components::IComponent> component = std::make_shared<ecs::components::Acceleration>();
    std::shared_ptr<entities::Entity> entity = std::make_shared<entities::Entity>();

    manager->addGameLogicComponent(component, 0);
    auto res = manager->getGameLogicComponents(0); 
    cr_assert(manager->getGameLogicComponents(0).size() == 1);
    cr_assert(manager->getDisplayComponents(0).size() == 0);
    cr_assert(manager->getIOComponents(0).size() == 0);
    cr_assert(manager->getPhysicComponents(0).size() == 0);
    cr_assert_eq(component->getType(), (*res.begin()).get()->getType());

    manager->removeComponents(0);
    res = manager->getGameLogicComponents(0);
    cr_assert(manager->getGameLogicComponents(0).size() == 0);
    cr_assert(manager->getDisplayComponents(0).size() == 0);
    cr_assert(manager->getIOComponents(0).size() == 0);
    cr_assert(manager->getPhysicComponents(0).size() == 0);

    manager->addGameLogicComponent(component, entity);
    res = manager->getGameLogicComponents(entity);
    cr_assert(manager->getGameLogicComponents(entity).size() == 1);
    cr_assert(manager->getDisplayComponents(entity).size() == 0);
    cr_assert(manager->getIOComponents(entity).size() == 0);
    cr_assert(manager->getPhysicComponents(entity).size() == 0);
    cr_assert_eq(component->getType(), (*res.begin()).get()->getType());
}