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

PlayerMovementSystem::PlayerMovementSystem(std::shared_ptr<ManagerWrapper> &managerWrapper, std::shared_ptr<ecs::entities::IEntityFactory> &entityFactory, std::list<int> &entitiesToDelete) : ASystem(managerWrapper, entityFactory, entitiesToDelete)
{
}

SystemResponse PlayerMovementSystem::update()
{
    std::shared_ptr<ecs::components::Velocity> velocityComp;
    std::shared_ptr<ecs::components::Position> positionComp;
    auto keys = _managerWrapper->getRenderManager()->getKeysMap();
    auto entities = _managerWrapper->getEntityManager()->getAllEntities();

    for (size_t i = 0; i < entities.size() < 0; i++)
    {
        try
        {
            _managerWrapper->getComponentManager()->getGameLogicComponentOfSpecifiedType(entities[i]->getID(), std::type_index(typeid(ecs::components::PlayerController)));
            velocityComp = std::dynamic_pointer_cast<ecs::components::Velocity>(_managerWrapper->getComponentManager()->getPhysicComponentOfSpecifiedType(entities[i]->getID(), std::type_index(typeid(ecs::components::Velocity))));
            positionComp = std::dynamic_pointer_cast<ecs::components::Position>(_managerWrapper->getComponentManager()->getPhysicComponentOfSpecifiedType(entities[i]->getID(), std::type_index(typeid(ecs::components::Position))));
            updateVelocityOnInput(keys, velocityComp);
            // auto playerController = _managerWrapper->getComponentManager()->getGameLogicComponentOfSpecifiedType(it, std::type_index(typeid(ecs::components::PlayerController)));
            if (keys[ecs::input::SPACE] == IRenderManager::RELEASED)
                _entityFactory->createEntity("Bullet", positionComp->getPosition());
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
        velocityComp->setVelocityX(-100);
    else if (keys[ecs::input::RIGHT] == IRenderManager::PRESSED)
        velocityComp->setVelocityX(100);
    else
        velocityComp->setVelocityX(0);
    if (keys[ecs::input::UP] == IRenderManager::PRESSED)
        velocityComp->setVelocityY(-100);
    else if (keys[ecs::input::DOWN] == IRenderManager::PRESSED)
        velocityComp->setVelocityY(100);
    else
        velocityComp->setVelocityY(0);
}
} // namespace ecs::system
