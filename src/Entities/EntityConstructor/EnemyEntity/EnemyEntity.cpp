/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** EnemyEntity.cpp
*/

#include "EnemyEntity.hpp"
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

std::shared_ptr<ecs::entities::Entity> EnemyEntity::create(
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

    Rect spriteRect(100, 91, 0, 0);
    entityManager->addEntity(toCreate);
    componentsManager->addPhysicComponent(std::make_shared<ecs::components::Position>(pos.first, pos.second), toCreate);
    componentsManager->addPhysicComponent(std::make_shared<ecs::components::Velocity>(-300, 50), toCreate);
    componentsManager->addPhysicComponent(std::make_shared<ecs::components::Rotation>(0), toCreate);
    componentsManager->addPhysicComponent(std::make_shared<ecs::components::Collision>(true, 0, 0, 90, 90, "Enemy1"), toCreate);    
    componentsManager->addGameLogicComponent(std::make_shared<ecs::components::Health>(200), toCreate);
    componentsManager->addGameLogicComponent(std::make_shared<ecs::components::EnemiesController>("Wave"), toCreate);
    componentsManager->addDisplayComponent(std::make_shared<ecs::components::Sprite>("enemy", spriteRect, true), toCreate);
    componentsManager->addDisplayComponent(std::make_shared<ecs::components::Animator>(spriteRect, 14), toCreate);
    return toCreate;   
}

std::string EnemyEntity::getName()
{
    return std::string("Enemy");
}