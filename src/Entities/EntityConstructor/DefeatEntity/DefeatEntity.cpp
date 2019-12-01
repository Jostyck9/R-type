/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** DefeatEntity.cpp
*/

#include "Button.hpp"
#include "DefeatEntity.hpp"
#include "Position.hpp"
#include "Text.hpp"

using namespace ecs::entities;

std::shared_ptr<ecs::entities::Entity> DefeatEntity::create(
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

    entityManager->addEntity(toCreate);
    componentsManager->addPhysicComponent(std::make_shared<ecs::components::Position>(360, 0), toCreate);
    componentsManager->addDisplayComponent(std::make_shared<ecs::components::Text>("DEFEAT", 150), toCreate);
    return toCreate;
}

std::string DefeatEntity::getName()
{
    return std::string("Defeat");
}