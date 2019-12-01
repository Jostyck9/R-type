/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** EnemyBulletEntity.cpp
*/

#include "Animator.hpp"
#include "EnemyBulletEntity.hpp"
#include "Rotation.hpp"
#include "Position.hpp"
#include "Velocity.hpp"
#include "Collision.hpp"
#include "Sprite.hpp"
#include "Damage.hpp"
#include "Rect.hpp"

using namespace ecs::entities;

std::shared_ptr<ecs::entities::Entity> EnemyBulletEntity::create(
    std::shared_ptr<IEntityManager> &entityManager,
    std::shared_ptr<ecs::components::IComponentManager> &componentsManager,
    std::pair<float, float> pos,
    std::pair<float, float> velocity,
    float rotation)
{
    static_cast<void>(rotation);
    static_cast<void>(velocity);

    std::shared_ptr<Entity> toCreate = std::make_shared<Entity>();

    Rect spriteRect(18, 15, 0, 0);
    entityManager->addEntity(toCreate);
    componentsManager->addPhysicComponent(std::make_shared<ecs::components::Position>(pos.first, pos.second), toCreate);
    componentsManager->addPhysicComponent(std::make_shared<ecs::components::Velocity>(-250, 0), toCreate);
    componentsManager->addPhysicComponent(std::make_shared<ecs::components::Rotation>(0), toCreate);
    componentsManager->addPhysicComponent(std::make_shared<ecs::components::Collision>(true, 0, 0, 1, 1, "EnemyBullet"), toCreate);
    componentsManager->addDisplayComponent(std::make_shared<ecs::components::Sprite>("enemyBullet", spriteRect, true), toCreate);
    componentsManager->addGameLogicComponent(std::make_shared<ecs::components::Damage>(10), toCreate);
    componentsManager->addDisplayComponent(std::make_shared<ecs::components::Animator>(spriteRect, 7), toCreate);
    return toCreate;
}

std::string EnemyBulletEntity::getName()
{
    return std::string("EnemyBullet");
}