/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** BackgroundWithoutTitleEntity.cpp
*/

#include "BackgroundWithoutTitleEntity.hpp"
#include "Position.hpp"
#include "Sprite.hpp"
#include "Velocity.hpp"
#include "Rotation.hpp"

using namespace ecs::entities;

std::shared_ptr<ecs::entities::Entity> BackgroundWithoutTitleEntity::create(
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

    Rect spriteRect(1500, 900, 0, 0);
    entityManager->addEntity(toCreate);
    componentsManager->addPhysicComponent(std::make_shared<ecs::components::Position>(0, 0), toCreate);
    componentsManager->addPhysicComponent(std::make_shared<ecs::components::Velocity>(0, 0), toCreate);
    componentsManager->addPhysicComponent(std::make_shared<ecs::components::Rotation>(0), toCreate);
    componentsManager->addDisplayComponent(std::make_shared<ecs::components::Sprite>("backgroundWithoutTitle", spriteRect, true), toCreate);
    return toCreate;
}

std::string BackgroundWithoutTitleEntity::getName()
{
    return std::string("BackgroundWithoutTitle");
}