/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** PlayerMovementSystem.cpp
*/

#include <IO/Sound.hpp>
#include "Health.hpp"
#include "Damage.hpp"
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
                updateVelocityOnInput(keys, velocityComp, playerControllerComp, positionComp);
                std::map<ecs::actions::Action, ecs::input::Key> keyMap = playerControllerComp->getMovementKeys();
                if (keys[keyMap[ecs::actions::SHOOT]] == IRenderManager::PRESSED) {
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
                std::map<size_t, std::string> collidedTags = std::reinterpret_pointer_cast<ecs::components::Collision>(_managerWrapper->getComponentManager()->getPhysicComponentOfSpecifiedType(entities[i]->getID(), std::type_index(typeid(ecs::components::Collision))))->getCollidedTags();
                for (auto it = collidedTags.begin(); it != collidedTags.end(); it ++) {
                    if (it->second == "EnemyBullet") {
                        auto healthComp = std::reinterpret_pointer_cast<ecs::components::Health>(
                                _managerWrapper->getComponentManager()->getGameLogicComponentOfSpecifiedType(
                                        entities[i]->getID(),
                                        std::type_index(typeid(ecs::components::Health))));
                        try {
                            auto damage = std::reinterpret_pointer_cast<ecs::components::Damage>(
                                    _managerWrapper->getComponentManager()->getGameLogicComponentOfSpecifiedType(
                                            it->first, std::type_index(typeid(ecs::components::Damage))));
                            healthComp->setValue(healthComp->getValue() - damage->getValue());
                        } catch (const ComponentExceptions &e) {
                            healthComp->setValue(healthComp->getValue() - 1);
                            continue;
                        }
                        if (healthComp->getValue() <= 0)
                            _entitiesToDelete.push_front(entities[i]->getID());
                    }
                    if (it->second == "Enemy")
                        _entitiesToDelete.push_front(entities[i]->getID());
                }
            } catch (const ComponentExceptions &e) {}
        }
        return SystemResponse();
    }

    void PlayerMovementSystem::updateVelocityOnInput(std::map<ecs::input::Key, IRenderManager::KEY_STATE> &keys,
                                                     std::shared_ptr<ecs::components::Velocity> &velocityComp,
                                                     std::shared_ptr<ecs::components::PlayerController> &playerComp,
                                                     std::shared_ptr<ecs::components::Position> &positionComp) {
        std::map<ecs::actions::Action, ecs::input::Key> keyMap = playerComp->getMovementKeys();
        if (keys[keyMap[ecs::actions::LEFT]] == IRenderManager::PRESSED && positionComp->getX() > 5)
            velocityComp->setVelocityX(-180);
        else if (keys[keyMap[ecs::actions::RIGHT]] == IRenderManager::PRESSED && positionComp->getX() < 1400)
            velocityComp->setVelocityX(180);
        else
            velocityComp->setVelocityX(0);
        if (keys[keyMap[ecs::actions::UP]] == IRenderManager::PRESSED && positionComp->getY() > 20)
            velocityComp->setVelocityY(-180);
        else if (keys[keyMap[ecs::actions::DOWN]] == IRenderManager::PRESSED && positionComp->getY() < 850)
            velocityComp->setVelocityY(180);
        else
            velocityComp->setVelocityY(0);
    }
}
