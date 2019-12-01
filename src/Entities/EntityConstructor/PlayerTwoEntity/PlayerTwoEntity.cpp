/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** PlayerTwoEntity.cpp
*/

#include <IO/Sound.hpp>
#include "PlayerTwoEntity.hpp"
#include "Physics/Rotation.hpp"
#include "Physics/Position.hpp"
#include "Physics/Velocity.hpp"
#include "Physics/Collision.hpp"
#include "Display/Sprite.hpp"
#include "Display/Animator.hpp"
#include "Display/Text.hpp"
#include "GameLogic/Health.hpp"
#include "PlayerController.hpp"
#include "Rect.hpp"

using namespace ecs::entities;

std::shared_ptr<ecs::entities::Entity> PlayerTwoEntity::create(
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

    Rect spriteRect(80, 40, 0, 0);
    entityManager->addEntity(toCreate);
    componentsManager->addPhysicComponent(std::make_shared<ecs::components::Position>(pos.first, pos.second), toCreate);
    componentsManager->addPhysicComponent(std::make_shared<ecs::components::Velocity>(0, 0), toCreate);
    componentsManager->addPhysicComponent(std::make_shared<ecs::components::Rotation>(0), toCreate);
    // componentsManager->addPhysicComponent(std::make_shared<ecs::components::Collision>(false, 0, 0, 20, 20, "Player"), toCreate);
    componentsManager->addDisplayComponent(std::make_shared<ecs::components::Sprite>("playerTwo", spriteRect, true), toCreate);
    componentsManager->addDisplayComponent(std::make_shared<ecs::components::Text>("P2", 15, 0, -20), toCreate);
    componentsManager->addDisplayComponent(std::make_shared<ecs::components::Animator>(spriteRect, 5), toCreate);
    componentsManager->addIOComponent(std::make_shared<ecs::components::Sound>("laser"), toCreate);
    componentsManager->addGameLogicComponent(std::make_shared<ecs::components::PlayerController>(false), toCreate);
    return toCreate;
}

std::string PlayerTwoEntity::getName()
{
    return std::string("PlayerTwo");
}