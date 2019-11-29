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

PlayerMovementSystem::PlayerMovementSystem(std::shared_ptr<ManagerWrapper> &managerWrapper, std::list<int> &entitiesToDelete) : ASystem(managerWrapper, entitiesToDelete)
{
}

void PlayerMovementSystem::update()
{
    std::shared_ptr<ecs::components::Velocity> velocityComp;
    std::map<ecs::input::Key, bool> keys = _managerWrapper->getRenderManager()->getKeysMap();
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
}

void PlayerMovementSystem::updateVelocityOnInput(std::map<ecs::input::Key, bool> &keys, std::shared_ptr<ecs::components::Velocity> &velocityComp)
{
    if (keys[ecs::input::LEFT])
        velocityComp->setVelocityX(-2);
    else if (keys[ecs::input::RIGHT])
    {
        velocityComp->setVelocityX(2);
    }
    else
    {        std::cout << "you dont press left nor right" << std::endl;

        velocityComp->setVelocityX(0);
    }
    if (keys[ecs::input::UP])
        velocityComp->setVelocityY(-2);
    else if (keys[ecs::input::DOWN]) {
        velocityComp->setVelocityY(2);
    }
    else {
        std::cout << "you dont press up nor down" << std::endl;
        velocityComp->setVelocityY(0);
    }
}
} // namespace ecs::system
