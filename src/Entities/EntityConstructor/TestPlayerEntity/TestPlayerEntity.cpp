/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** TestPlayerEntity.cpp
*/

#include "TestPlayerEntity.hpp"
#include "Physics/Rotation.hpp"
#include "Physics/Position.hpp"
#include "Physics/Velocity.hpp"
#include "Physics/Collision.hpp"
#include "Display/Sprite.hpp"

using namespace ecs::entities;

std::shared_ptr<ecs::entities::Entity> TestPlayerEntity::create(
    std::shared_ptr<IEntityManager> &entityManager,
    std::shared_ptr<ecs::components::IComponentManager> &componentsManager)
{
    std::shared_ptr<Entity> toCreate = std::make_shared<Entity>();

    entityManager->addEntity(toCreate);
    componentsManager->addPhysicComponent(std::make_shared<ecs::components::Position>(0, 0), toCreate);
    componentsManager->addPhysicComponent(std::make_shared<ecs::components::Velocity>(1, 0), toCreate);
    componentsManager->addPhysicComponent(std::make_shared<ecs::components::Rotation>(0), toCreate);
    componentsManager->addPhysicComponent(std::make_shared<ecs::components::Collision>(true, 0, 0, 1, 1, "Test"), toCreate);
    // componentsManager->addDisplayComponent(std::make_shared<ecs::components::Sprite>("r-typesheet42.gif"), toCreate);
    return toCreate;
}

std::string TestPlayerEntity::getName()
{
    return std::string("TestPlayer");
}