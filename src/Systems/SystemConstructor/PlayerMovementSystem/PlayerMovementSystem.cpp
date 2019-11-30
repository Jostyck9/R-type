/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** PlayerMovementSystem.cpp
*/

#include <iostream>
#include "Physics/Velocity.hpp"
#include "ComponentExceptions.hpp"
#include "PlayerMovementSystem.hpp"

namespace ecs::system
{

PlayerMovementSystem::PlayerMovementSystem(std::shared_ptr<IManagerWrapper> &managerWrapper, std::shared_ptr<ecs::entities::IEntityFactory> &entityFactory, std::list<int> &entitiesToDelete) : ASystem(managerWrapper, entityFactory, entitiesToDelete)
{
}

SystemResponse PlayerMovementSystem::update()
{
    std::shared_ptr<ecs::components::Velocity> velocityComp;
    auto keys = _managerWrapper->getRenderManager()->getKeysMap();
    for (auto &it : _managerWrapper->getEntityManager()->getAllEntities())
    {
        try
        {
            std::dynamic_pointer_cast<ecs::components::PlayerController>(_managerWrapper->getComponentManager()->getGameLogicComponentOfSpecifiedType(it->getID(), std::type_index(typeid(ecs::components::PlayerController))));
            velocityComp = std::dynamic_pointer_cast<ecs::components::Velocity>(_managerWrapper->getComponentManager()->getPhysicComponentOfSpecifiedType(it->getID(), std::type_index(typeid(ecs::components::Velocity))));
            updateVelocityOnInput(keys, velocityComp);
        }
        catch (const ComponentExceptions &e)
        {
        }
    }
    return SystemResponse();
}

void PlayerMovementSystem::updateVelocityOnInput(std::map<ecs::input::Key, IRenderManager::KEY_STATE> &keys, std::shared_ptr<ecs::components::Velocity> &velocityComp)
{
    if (keys[ecs::input::LEFT] == IRenderManager::PRESSED)
        velocityComp->setVelocityX(-180);
    else if (keys[ecs::input::RIGHT] == IRenderManager::PRESSED)
    {
        velocityComp->setVelocityX(180);
    }
    else
    {
        velocityComp->setVelocityX(0);
    }
    if (keys[ecs::input::UP] == IRenderManager::PRESSED)
        velocityComp->setVelocityY(-180);
    else if (keys[ecs::input::DOWN] == IRenderManager::PRESSED) {
        velocityComp->setVelocityY(180);
    }
    else {
        velocityComp->setVelocityY(0);
    }
}
} // namespace ecs::system
