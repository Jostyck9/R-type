/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** PlayEntity.cpp
*/

#include <Display/Button.hpp>
#include "StopEntity.hpp"
#include "Position.hpp"
#include "Text.hpp"

using namespace ecs::entities;

std::shared_ptr<ecs::entities::Entity> StopEntity::create(
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
    componentsManager->addPhysicComponent(std::make_shared<ecs::components::Position>(1020, 700), toCreate);
    componentsManager->addDisplayComponent(std::make_shared<ecs::components::Text>("EXIT", 50), toCreate);
    componentsManager->addDisplayComponent(std::make_shared<ecs::components::Button>(false, ecs::system::SystemResponse::CMD::QUIT), toCreate);
    return toCreate;
}

std::string StopEntity::getName()
{
    return std::string("Stop");
}