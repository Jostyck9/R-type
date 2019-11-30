/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** WallSideEntity.cpp
*/

#include "WallSideEntity.hpp"
#include "Rotation.hpp"
#include "Position.hpp"
#include "Collision.hpp"
#include "Velocity.hpp"

using namespace ecs::entities;

std::shared_ptr<ecs::entities::Entity> WallSideEntity::create(
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
    componentsManager->addPhysicComponent(std::make_shared<ecs::components::Rotation>(0), toCreate);
    componentsManager->addPhysicComponent(std::make_shared<ecs::components::Velocity>(0, 0), toCreate);
    componentsManager->addPhysicComponent(std::make_shared<ecs::components::Collision>(false, 0, 0, 100, 2000, "Wall"), toCreate);
    return toCreate;
}

std::string WallSideEntity::getName()
{
    return std::string("WallSide");
}