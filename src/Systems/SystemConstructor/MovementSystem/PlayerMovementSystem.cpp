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

const ecs::input::Key ecs::system::PlayerMovementSystem::movePlayerUp = ecs::input::UP;
const ecs::input::Key ecs::system::PlayerMovementSystem::movePlayerDown = ecs::input::DOWN;
const ecs::input::Key ecs::system::PlayerMovementSystem::movePlayerLeft = ecs::input::LEFT;
const ecs::input::Key ecs::system::PlayerMovementSystem::movePlayerRight = ecs::input::RIGHT;

namespace ecs::system
{

PlayerMovementSystem::PlayerMovementSystem(std::shared_ptr<ManagerWrapper> &managerWrapper, std::list<int> &entitiesToDelete) : ASystem(managerWrapper, entitiesToDelete)
{
}

void PlayerMovementSystem::update()
{
    std::shared_ptr<ecs::components::Velocity> velocityComp;
    std::vector<ecs::input::Key> inputs = _managerWrapper->getRenderManager()->getInputs();
    for (auto &it : _managerWrapper->getEntityManager()->getAllEntities())
    {
        try
        {
            std::dynamic_pointer_cast<ecs::components::PlayerController>(_managerWrapper->getComponentManager()->getGameLogicComponentOfSpecifiedType(it->getID(), std::type_index(typeid(ecs::components::PlayerController))));
            velocityComp = std::dynamic_pointer_cast<ecs::components::Velocity>(_managerWrapper->getComponentManager()->getPhysicComponentOfSpecifiedType(it->getID(), std::type_index(typeid(ecs::components::Velocity))));
            updateVelocityOnInput(inputs, velocityComp);
        }
        catch (const ComponentExceptions &e)
        {
        }
    }
}

void PlayerMovementSystem::updateVelocityOnInput(std::vector<ecs::input::Key> &inputs, std::shared_ptr<ecs::components::Velocity> &velocityComp)
{
    if (std::find(inputs.begin(), inputs.end(), PlayerMovementSystem::movePlayerUp) != inputs.end())
    {
        velocityComp->setVelocityY((velocityComp->getVelocityY() - 1));
    }
    else if (std::find(inputs.begin(), inputs.end(), PlayerMovementSystem::movePlayerDown) != inputs.end())
    {
        velocityComp->setVelocityY((velocityComp->getVelocityY() + 1));
    }
    else
    {
        velocityComp->setVelocityY(0);
    }
    if (std::find(inputs.begin(), inputs.end(), PlayerMovementSystem::movePlayerRight) != inputs.end())
    {
        velocityComp->setVelocityX((velocityComp->getVelocityX() + 1));
    }
    else if (std::find(inputs.begin(), inputs.end(), PlayerMovementSystem::movePlayerLeft) != inputs.end())
    {
        velocityComp->setVelocityX((velocityComp->getVelocityX() - 1));
    }
    else
    {
        velocityComp->setVelocityX(0);
    }
}
} // namespace ecs::system
