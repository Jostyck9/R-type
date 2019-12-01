/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** NameRoomEntity.cpp
*/

#include <Display/Text.hpp>
#include <Physics/Position.hpp>
#include <Display/Button.hpp>
#include "NameRoomEntity.hpp"

using namespace ecs::entities;

std::shared_ptr<ecs::entities::Entity> NameRoomEntity::create(
    std::shared_ptr<IEntityManager> &entityManager,
    std::shared_ptr<ecs::components::IComponentManager> &componentsManager,
    std::pair<float, float> pos,
    std::pair<float, float> velocity,
    float rotation)
{
    static_cast<void>(rotation);
    static_cast<void>(velocity);

    std::shared_ptr<Entity> toCreate = std::make_shared<Entity>();

    entityManager->addEntity(toCreate);
    componentsManager->addPhysicComponent(std::make_shared<ecs::components::Position>(pos.first, pos.second), toCreate);
    componentsManager->addDisplayComponent(std::make_shared<ecs::components::Text>("ROOM", 40), toCreate);
    componentsManager->addDisplayComponent(std::make_shared<ecs::components::Button>(false, ecs::system::SystemResponse::CMD::LOADSCENE, "Game"), toCreate);
    return toCreate;
}

std::string NameRoomEntity::getName()
{
    return std::string("ListRoom");
}

extern "C"
{
    ecs::entities::IEntityConstructor *entryPoint()
    {
        return (new ecs::entities::NameRoomEntity());
    }
}