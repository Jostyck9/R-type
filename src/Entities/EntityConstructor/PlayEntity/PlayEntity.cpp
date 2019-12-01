/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** PlayEntity.cpp
*/

#include <Display/Button.hpp>
#include "PlayEntity.hpp"
#include "Position.hpp"
#include "Text.hpp"

using namespace ecs::entities;

std::shared_ptr<ecs::entities::Entity> PlayEntity::create(
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
    componentsManager->addPhysicComponent(std::make_shared<ecs::components::Position>(300, 700), toCreate);
    componentsManager->addDisplayComponent(std::make_shared<ecs::components::Text>("PLAY", 50), toCreate);
    componentsManager->addDisplayComponent(std::make_shared<ecs::components::Button>(true, ecs::system::SystemResponse::CMD::LOADSCENE, "ChooseRoomSystem"), toCreate);
    return toCreate;
}

std::string PlayEntity::getName()
{
    return std::string("Play");
}

extern "C"
{
    ecs::entities::IEntityConstructor *entryPoint()
    {
        return (new ecs::entities::PlayEntity());
    }
}