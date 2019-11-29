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
    std::vector<ecs::input::Key>
        inputs = _managerWrapper->getRenderManager()->getInputs();
    for (auto &it : _managerWrapper->getEntityManager()->getAllEntities())
    {
        try
        {           
            std::cout << "MEGAPUTE" <<std::endl;
            std::dynamic_pointer_cast<ecs::components::PlayerController>(_managerWrapper->getComponentManager()->getGameLogicComponentOfSpecifiedType(it->getID(), std::type_index(typeid(ecs::components::PlayerController))));
            std::cout << "TURBOPUTE" <<std::endl;
            velocityComp = std::dynamic_pointer_cast<ecs::components::Velocity>(_managerWrapper->getComponentManager()->getPhysicComponentOfSpecifiedType(it->getID(), std::type_index(typeid(ecs::components::Velocity))));
            std::cout << "CLEMENTPUTE" <<std::endl;
            if (std::find(inputs.begin(), inputs.end(), PlayerMovementSystem::movePlayerUp) != inputs.end())
            {
                velocityComp->setVelocityY((velocityComp->getVelocityY() - 1));
                std::cout << "pute up " << std::endl;
            }
        }
        catch (const ComponentExceptions &e)
        { 
        }
    }
}

} // namespace ecs::system