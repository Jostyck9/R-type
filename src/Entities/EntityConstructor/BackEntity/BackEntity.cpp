/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** BackEntity.cpp
*/

#include <Display/Button.hpp>
#include "BackEntity.hpp"
#include "Position.hpp"
#include "Text.hpp"

using namespace ecs::entities;

std::shared_ptr<ecs::entities::Entity> BackEntity::create(
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
    componentsManager->addPhysicComponent(std::make_shared<ecs::components::Position>(100, 800), toCreate);
    componentsManager->addDisplayComponent(std::make_shared<ecs::components::Text>("BACK", 30), toCreate);
    componentsManager->addDisplayComponent(std::make_shared<ecs::components::Button>(false, ecs::system::SystemResponse::CMD::LOADSCENE, "Menu"), toCreate);
    return toCreate;
}

std::string BackEntity::getName()
{
    return std::string("Back");
}