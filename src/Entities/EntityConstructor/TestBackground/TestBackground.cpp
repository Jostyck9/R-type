/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** TestBackground.cpp
*/

#include "TestBackground.hpp"
#include "Physics/Rotation.hpp"
#include "Physics/Position.hpp"
#include "Physics/Velocity.hpp"
#include "Physics/Collision.hpp"
#include "Display/Sprite.hpp"
#include "Display/Animator.hpp"
#include "Display/Text.hpp"
#include "GameLogic/Health.hpp"
#include "PlayerController.hpp"
#include "Rect.hpp"

using namespace ecs::entities;

std::shared_ptr<ecs::entities::Entity> TestBackground::create(
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

    Rect spriteRect(1500, 600, 0, 0);
    entityManager->addEntity(toCreate);
    componentsManager->addPhysicComponent(std::make_shared<ecs::components::Position>(0, 0), toCreate);
    componentsManager->addPhysicComponent(std::make_shared<ecs::components::Velocity>(0, 0), toCreate);
    componentsManager->addPhysicComponent(std::make_shared<ecs::components::Rotation>(0), toCreate);
    componentsManager->addDisplayComponent(std::make_shared<ecs::components::Sprite>("gameBackground", spriteRect, true), toCreate);
    return toCreate;
}

std::string TestBackground::getName()
{
    return std::string("TestBackground");
}

extern "C"
{
    ecs::entities::IEntityConstructor *entryPoint()
    {
        return (new ecs::entities::TestBackground());
    }
}