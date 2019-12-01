/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** EnnemyEntity.cpp
*/

#include "EnnemyEntity.hpp"
#include "Physics/Rotation.hpp"
#include "Physics/Position.hpp"
#include "Physics/Velocity.hpp"
#include "Physics/Collision.hpp"
#include "Display/Sprite.hpp"
#include "Display/Text.hpp"
#include "GameLogic/EnnemiesController.hpp"
#include "Rect.hpp"
#include "Animator.hpp"

using namespace ecs::entities;

std::shared_ptr<ecs::entities::Entity> EnnemyEntity::create(
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

    Rect spriteRect(99, 90, 0, 0);
    entityManager->addEntity(toCreate);
    componentsManager->addPhysicComponent(std::make_shared<ecs::components::Position>(700, 300), toCreate);
    componentsManager->addPhysicComponent(std::make_shared<ecs::components::Velocity>(-90, 0), toCreate);
    componentsManager->addPhysicComponent(std::make_shared<ecs::components::Rotation>(0), toCreate);
    componentsManager->addPhysicComponent(std::make_shared<ecs::components::Collision>(true, 0, 0, 1, 1, "Test"), toCreate);
    componentsManager->addGameLogicComponent(std::make_shared<ecs::components::EnnemiesController>("Wave"), toCreate);
    componentsManager->addDisplayComponent(std::make_shared<ecs::components::Sprite>("ennemy", spriteRect, true), toCreate);
    componentsManager->addDisplayComponent(std::make_shared<ecs::components::Animator>(spriteRect, 7), toCreate);
    return toCreate;
}

std::string EnnemyEntity::getName()
{
    return std::string("Ennemy");
}

extern "C"
{
    ecs::entities::IEntityConstructor *entryPoint()
    {
        return (new ecs::entities::EnnemyEntity());
    }
}