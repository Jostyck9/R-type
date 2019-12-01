/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** EnemyType02Entity.cpp
*/

#include "EnemyType02Entity.hpp"
#include "Physics/Rotation.hpp"
#include "Physics/Position.hpp"
#include "Physics/Velocity.hpp"
#include "Physics/Collision.hpp"
#include "Display/Sprite.hpp"
#include "Display/Text.hpp"
#include "GameLogic/EnemiesController.hpp"
#include "Rect.hpp"
#include "Animator.hpp"
#include "Health.hpp"

using namespace ecs::entities;

std::shared_ptr<ecs::entities::Entity> EnemyType02Entity::create(
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

    Rect spriteRect(139, 144, 0, 0);
    entityManager->addEntity(toCreate);
    componentsManager->addPhysicComponent(std::make_shared<ecs::components::Position>(pos.first, pos.second), toCreate);
    componentsManager->addPhysicComponent(std::make_shared<ecs::components::Velocity>(-150, -100), toCreate);
    componentsManager->addPhysicComponent(std::make_shared<ecs::components::Rotation>(0), toCreate);
    // componentsManager->addPhysicComponent(std::make_shared<ecs::components::Collision>(true, 0, 0, 1, 1, "Test"), toCreate);
    componentsManager->addGameLogicComponent(std::make_shared<ecs::components::EnemiesController>("Wave"), toCreate);
    componentsManager->addGameLogicComponent(std::make_shared<ecs::components::Health>(200), toCreate);
    componentsManager->addDisplayComponent(std::make_shared<ecs::components::Sprite>("enemyType02", spriteRect, true), toCreate);
    componentsManager->addDisplayComponent(std::make_shared<ecs::components::Animator>(spriteRect, 2, 0.2), toCreate);
    return toCreate;
}

std::string EnemyType02Entity::getName()
{
    return std::string("EnemyType02");
}