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
#include "Display/Text.hpp"
#include "PlayerController.hpp"
#include "Rect.hpp"

using namespace ecs::entities;

std::shared_ptr<ecs::entities::Entity> TestPlayerEntity::create(
    std::shared_ptr<IEntityManager> &entityManager,
    std::shared_ptr<ecs::components::IComponentManager> &componentsManager,
    std::pair<float, float> pos,
    std::pair<float, float> velocity,
    float rotation)
{
    static_cast<void>(rotation);
    static_cast<void>(pos);
    static_cast<void>(velocity);

    std::shared_ptr<Entity> toCreate = std::make_shared<Entity>();

    Rect spriteRect(50, 50, 0, 0);
    entityManager->addEntity(toCreate);
    componentsManager->addPhysicComponent(std::make_shared<ecs::components::Position>(30, 30), toCreate);
    componentsManager->addPhysicComponent(std::make_shared<ecs::components::Velocity>(0, 0), toCreate);
    componentsManager->addPhysicComponent(std::make_shared<ecs::components::Rotation>(0), toCreate);
    componentsManager->addPhysicComponent(std::make_shared<ecs::components::Collision>(true, 0, 0, 1, 1, "Test"), toCreate);
    componentsManager->addDisplayComponent(std::make_shared<ecs::components::Sprite>("player", spriteRect), toCreate);
    componentsManager->addDisplayComponent(std::make_shared<ecs::components::Text>("P1", 15), toCreate);
    componentsManager->addGameLogicComponent(std::make_shared<ecs::components::PlayerController>(), toCreate);
    return toCreate;
}

std::string TestPlayerEntity::getName()
{
    return std::string("TestPlayer");
}