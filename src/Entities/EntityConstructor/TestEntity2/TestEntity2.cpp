/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** TestEntity2.cpp
*/

#include "TestEntity2.hpp"
#include "Physics/Rotation.hpp"
#include "Physics/Position.hpp"
#include "Physics/Velocity.hpp"
#include "Physics/Collision.hpp"
#include "ManagerWrapper.hpp"

using namespace ecs::entities;

std::shared_ptr<ecs::entities::Entity> TestEntity2::create(
    std::shared_ptr<IEntityManager> &entityManager,
    std::shared_ptr<ecs::components::IComponentManager> &componentsManager)
{
    std::shared_ptr<Entity> toCreate = std::make_shared<Entity>();

    entityManager->addEntity(toCreate);
    componentsManager->addPhysicComponent(std::make_shared<ecs::components::Position>(5, 0), toCreate);
    componentsManager->addPhysicComponent(std::make_shared<ecs::components::Velocity>(0, 0), toCreate);
    componentsManager->addPhysicComponent(std::make_shared<ecs::components::Rotation>(0), toCreate);
    componentsManager->addPhysicComponent(std::make_shared<ecs::components::Collision>(true, 0, 0, 1, 1, "Test2"), toCreate);
    return toCreate;
}

std::string TestEntity2::getName()
{
    return std::string("Test2");
}

extern "C"
{
    std::shared_ptr<ecs::entities::IEntityConstructor> entryPoint()
    {
        return (std::make_shared<ecs::entities::TestEntity2>());
    }
}