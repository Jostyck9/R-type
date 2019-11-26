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
        time_t currentTime = time(NULL);
        while ((currentTime - this->_elapsedTime) < 2) {
            currentTime = time(NULL);
        }
        this->_elapsedTime = time(NULL);
        std::cout << " YEETUPDATED" << std::endl;
        //est ce qu'on rajoute un state pour savoir quelle entity doivent etre display ?
        // for (auto &it : _entityManager->getAllEntities()) {
        //     // auto ImageComponent = _componentManager->getDisplayComponentOfSpecifiedType(it->getID(),std::type_index(typeid(ecs::components::Image)));
        //     // auto bruh = std::dynamic_pointer_cast<ecs::components::Image>(ImageComponent);
        //     std::cout << "show image " << std::endl;
        // }
    }
}