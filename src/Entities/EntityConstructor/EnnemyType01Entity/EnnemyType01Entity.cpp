/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** EnnemyType01Entity.cpp
*/

#include "EnnemyType01Entity.hpp"
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

std::shared_ptr<ecs::entities::Entity> EnnemyType01Entity::create(
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

    Rect spriteRect(159, 160, 0, 0);
    entityManager->addEntity(toCreate);
    componentsManager->addPhysicComponent(std::make_shared<ecs::components::Position>(700, 90), toCreate);
    componentsManager->addPhysicComponent(std::make_shared<ecs::components::Velocity>(-60, 0), toCreate);
    componentsManager->addPhysicComponent(std::make_shared<ecs::components::Rotation>(0), toCreate);
    componentsManager->addPhysicComponent(std::make_shared<ecs::components::Collision>(false, 0, 0, 159, 160, "Ennemy"), toCreate);
    componentsManager->addGameLogicComponent(std::make_shared<ecs::components::EnnemiesController>("Basic"), toCreate);
    componentsManager->addDisplayComponent(std::make_shared<ecs::components::Sprite>("ennemyType01", spriteRect, true), toCreate);
    componentsManager->addDisplayComponent(std::make_shared<ecs::components::Animator>(spriteRect, 5), toCreate);
    return toCreate;
}

std::string EnnemyType01Entity::getName()
{
    return std::string("EnnemyType01");
}