/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** test.cpp
*/

#include <memory>
#include <criterion/criterion.h>
#include "IComponentManager.hpp"
#include "ComponentManager.hpp"
#include "Acceleration.hpp"

Test(sample, test) {
    std::unique_ptr<components::IComponentManager> manager = std::make_unique<components::ComponentManager>();
    std::shared_ptr<components::IComponent> component = std::make_shared<components::Acceleration>();

    manager->addPhysicComponent(component, 0);
    auto res = manager->getPhysicComponent(0);
    cr_assert(res.size() == 1);
}