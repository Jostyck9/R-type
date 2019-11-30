/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** PlayerMovementSystem.cpp
*/

#include <iostream>
#include <IO/Sound.hpp>
#include "Physics/Velocity.hpp"
#include "ComponentExceptions.hpp"
#include "PlayerMovementSystem.hpp"

namespace ecs::system {

    PlayerMovementSystem::PlayerMovementSystem(std::shared_ptr<IManagerWrapper> &managerWrapper,
                                               std::shared_ptr<ecs::entities::IEntityFactory> &entityFactory,
                                               std::list<int> &entitiesToDelete) : ASystem(managerWrapper,
                                                                                           entityFactory,
                                                                                           entitiesToDelete) {
    }

    SystemResponse PlayerMovementSystem::update() {
        std::shared_ptr<ecs::components::PlayerController> playerControllerComp;
        std::shared_ptr<ecs::components::Velocity> velocityComp;
        std::shared_ptr<ecs::components::Position> positionComp;
        auto keys = _managerWrapper->getRenderManager()->getKeysMap();
        auto entities = _managerWrapper->getEntityManager()->getAllEntities();

        for (size_t i = 0; i < entities.size(); i++) {
            try {
                playerControllerComp = std::reinterpret_pointer_cast<ecs::components::PlayerController>(
                        _managerWrapper->getComponentManager()->getGameLogicComponentOfSpecifiedType(
                                entities[i]->getID(), std::type_index(typeid(ecs::components::PlayerController))));
                velocityComp = std::reinterpret_pointer_cast<ecs::components::Velocity>(
                        _managerWrapper->getComponentManager()->getPhysicComponentOfSpecifiedType(entities[i]->getID(),
                                                                                                  std::type_index(
                                                                                                          typeid(ecs::components::Velocity))));
                positionComp = std::reinterpret_pointer_cast<ecs::components::Position>(
                        _managerWrapper->getComponentManager()->getPhysicComponentOfSpecifiedType(entities[i]->getID(),
                                                                                                  std::type_index(
                                                                                                          typeid(ecs::components::Position))));
                updateVelocityOnInput(keys, velocityComp);
                if (keys[ecs::input::SPACE] == IRenderManager::PRESSED) {
                    if (playerControllerComp->getTimer().getElapsedMilliseconds() >=
                        playerControllerComp->getTimer().getEndTime()) {
                        _entityFactory->createEntity("Bullet", std::make_pair(positionComp->getPosition().first + 50,
                                                                              positionComp->getPosition().second + 20));
                        try {
                            auto sound = std::reinterpret_pointer_cast<ecs::components::Sound>(_managerWrapper->getComponentManager()->getIOComponentOfSpecifiedType(entities[i]->getID(),
                                                                                                  std::type_index(
                                                                                                          typeid(ecs::components::Sound))));
                            _managerWrapper->getResourceManager()->getSound(sound->getNameSound())->play();
                        } catch (const ComponentExceptions &e) {}
                        playerControllerComp->getTimer().restart(500);
                    }
                }
            } catch (const ComponentExceptions &e) {}
        }
        return SystemResponse();
    }

    void PlayerMovementSystem::updateVelocityOnInput(std::map<ecs::input::Key, IRenderManager::KEY_STATE> &keys,
                                                     std::shared_ptr<ecs::components::Velocity> &velocityComp) {
        if (keys[ecs::input::LEFT] == IRenderManager::PRESSED)
            velocityComp->setVelocityX(-180);
        else if (keys[ecs::input::RIGHT] == IRenderManager::PRESSED)
            velocityComp->setVelocityX(180);
        else
            velocityComp->setVelocityX(0);
        if (keys[ecs::input::UP] == IRenderManager::PRESSED)
            velocityComp->setVelocityY(-180);
        else if (keys[ecs::input::DOWN] == IRenderManager::PRESSED)
            velocityComp->setVelocityY(180);
        else
            velocityComp->setVelocityY(0);
    }
}
