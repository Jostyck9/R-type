/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** TestEntity.cpp
*/

#include "TestEntity.hpp"
#include "Physics/Rotation.hpp"
#include "Physics/Position.hpp"
#include "Physics/Velocity.hpp"
#include "Physics/Collision.hpp"

using namespace ecs::entities;

std::shared_ptr<ecs::entities::Entity> TestEntity::create(
    std::shared_ptr<IEntityManager> &entityManager,
    std::shared_ptr<ecs::components::IComponentManager> &componentsManager)
{
    std::shared_ptr<Entity> toCreate = std::make_shared<Entity>();

    entityManager->addEntity(toCreate);
    componentsManager->addPhysicComponent(std::make_shared<ecs::components::Position>(0, 0), toCreate);
    componentsManager->addPhysicComponent(std::make_shared<ecs::components::Velocity>(1, 0), toCreate);
    componentsManager->addPhysicComponent(std::make_shared<ecs::components::Rotation>(0), toCreate);
    componentsManager->addPhysicComponent(std::make_shared<ecs::components::Collision>(true, 0, 0, 1, 1, "Test"), toCreate);
    return toCreate;
}

std::string TestEntity::getName()
{
    return std::string("Test");
}