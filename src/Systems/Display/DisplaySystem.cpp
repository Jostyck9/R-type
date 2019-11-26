/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** DisplaySystem.cpp
*/

#include <iostream>
#include "Physics/Position.hpp"
#include "Physics/Velocity.hpp"
#include "Display/Image.hpp"
#include "DisplaySystem.hpp"
#include "Collision.hpp"
#include "ComponentExceptions.hpp"

namespace ecs::system
{
    DisplaySystem::DisplaySystem(std::shared_ptr<ManagerWrapper> &managerWrapper, std::list<int> &entitiesToDelete) : 
    ASystem(managerWrapper, entitiesToDelete), _elapsedTime(0)
    {
        this->_elapsedTime = time(NULL);
    }
    
    DisplaySystem::~DisplaySystem()
    {
    }

    void DisplaySystem::update()
    {
        for (auto &it : _managerWrapper->getEntityManager()->getAllEntities()) {
            auto PosComponent = _managerWrapper->getComponentManager()->getPhysicComponentOfSpecifiedType(it->getID(),std::type_index(typeid(ecs::components::Position)));
            auto position = std::dynamic_pointer_cast<ecs::components::Position>(PosComponent);
            std::cout << "Update position : " << int(position->getX()) << " " << int(position->getY()) << std::endl;
            try {
                auto colision = std::reinterpret_pointer_cast<ecs::components::Collision>(_managerWrapper->getComponentManager()->getPhysicComponentOfSpecifiedType(it->getID(), std::type_index(typeid(ecs::components::Collision))));
                for (auto &it2 : colision->getCollidedTags()) {
                    std::cout << "colision on " << it->getID() << " by " << it2.first << " on tag : " << it2.second << std::endl;
                }
            } catch (ComponentExceptions &e) {
            }
        }
        // time_t currentTime = time(NULL); // TODO timer qui bloque le programme donc ca va pas 
        // while ((currentTime - this->_elapsedTime) < 2) {
        //     currentTime = time(NULL);
        // }
        // this->_elapsedTime = time(NULL);
        // std::cout << " YEETUPDATED" << std::endl;
        //est ce qu'on rajoute un state pour savoir quelle entity doivent etre display ?
        // for (auto &it : _entityManager->getAllEntities()) {
        //     // auto ImageComponent = _componentManager->getDisplayComponentOfSpecifiedType(it->getID(),std::type_index(typeid(ecs::components::Image)));
        //     // auto bruh = std::dynamic_pointer_cast<ecs::components::Image>(ImageComponent);
        //     std::cout << "show image " << std::endl;
        // }
    }
}