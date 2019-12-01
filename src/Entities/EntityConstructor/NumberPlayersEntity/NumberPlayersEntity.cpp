/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** NumberPlayersEntity.cpp
*/

#include <Display/Text.hpp>
#include <Physics/Position.hpp>
#include "NumberPlayersEntity.hpp"

using namespace ecs::entities;

std::shared_ptr<ecs::entities::Entity> NumberPlayersEntity::create(
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
    componentsManager->addPhysicComponent(std::make_shared<ecs::components::Position>(pos.first, pos.second), toCreate);
    componentsManager->addDisplayComponent(std::make_shared<ecs::components::Text>("0 / 4", 40), toCreate);
    return toCreate;
}

std::string NumberPlayersEntity::getName()
{
    return std::string("NumberPlayers");
}

extern "C"
{
    ecs::entities::IEntityConstructor *entryPoint()
    {
        return (new ecs::entities::NumberPlayersEntity());
    }
}