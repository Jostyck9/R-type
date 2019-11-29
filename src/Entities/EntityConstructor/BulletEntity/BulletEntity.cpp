/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** BulletEntity.cpp
*/

#include "BulletEntity.hpp"
#include "Physics/Rotation.hpp"
#include "Physics/Position.hpp"
#include "Physics/Velocity.hpp"
#include "Physics/Collision.hpp"
#include "Display/Sprite.hpp"
#include "Display/Text.hpp"
#include "GameLogic/Damage.hpp"
#include "Rect.hpp"

using namespace ecs::entities;

std::shared_ptr<ecs::entities::Entity> BulletEntity::create(
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

    Rect spriteRect(25, 10, 0, 0);
    entityManager->addEntity(toCreate);
    componentsManager->addPhysicComponent(std::make_shared<ecs::components::Position>(70, 70), toCreate);
    componentsManager->addPhysicComponent(std::make_shared<ecs::components::Velocity>(15, 0), toCreate);
    componentsManager->addPhysicComponent(std::make_shared<ecs::components::Rotation>(0), toCreate);
    componentsManager->addPhysicComponent(std::make_shared<ecs::components::Collision>(true, 0, 0, 1, 1, "Test"), toCreate);
    componentsManager->addDisplayComponent(std::make_shared<ecs::components::Sprite>("bullet", spriteRect, true), toCreate);
    componentsManager->addGameLogicComponent(std::make_shared<ecs::components::Damage>(10), toCreate);
    return toCreate;
}

std::string BulletEntity::getName()
{
    return std::string("Bullet");
}