/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** PlayEntity.cpp
*/

#include "PlayEntity.hpp"
#include "Position.hpp"
#include "Text.hpp"

using namespace ecs::entities;

std::shared_ptr<ecs::entities::Entity> PlayEntity::create(
    std::shared_ptr<IEntityManager> &entityManager,
    std::shared_ptr<ecs::components::IComponentManager> &componentsManager)
{
    std::shared_ptr<Entity> toCreate = std::make_shared<Entity>();

    entityManager->addEntity(toCreate);
    componentsManager->addPhysicComponent(std::make_shared<ecs::components::Position>(50, 200), toCreate);
    componentsManager->addDisplayComponent(std::make_shared<ecs::components::Text>("PLAY", 30), toCreate);
    return toCreate;
}

std::string PlayEntity::getName()
{
    return std::string("Play");
}