/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** PlayEntity.cpp
*/

#include "StopEntity.hpp"
#include "Position.hpp"
#include "Text.hpp"

using namespace ecs::entities;

std::shared_ptr<ecs::entities::Entity> StopEntity::create(
    std::shared_ptr<IEntityManager> &entityManager,
    std::shared_ptr<ecs::components::IComponentManager> &componentsManager)
{
    std::shared_ptr<Entity> toCreate = std::make_shared<Entity>();

    entityManager->addEntity(toCreate);
    componentsManager->addPhysicComponent(std::make_shared<ecs::components::Position>(500, 200), toCreate);
    componentsManager->addDisplayComponent(std::make_shared<ecs::components::Text>("EXIT", 30), toCreate);
    return toCreate;
}

std::string StopEntity::getName()
{
    return std::string("Stop");
}