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
    DisplaySystem::DisplaySystem(std::shared_ptr<entities::IEntityManager> &entityManager, std::shared_ptr<ecs::components::IComponentManager> &componentManager, std::list<int> &entitiesToDelete) : 
    ASystem(entityManager, componentManager, entitiesToDelete), _elapsedTime(0)
    {
        this->_elapsedTime = time(NULL);
    }
    
    DisplaySystem::~DisplaySystem()
    {
    }

    void DisplaySystem::update()
    {
        time_t currentTime = time(NULL);
        while ((currentTime - this->_elapsedTime) < 5) {
            currentTime = time(NULL);
        }
        this->_elapsedTime = time(NULL);
        std::cout << " YEETUPDATED" << std::endl;
        // for (auto &it : _entityManager->getAllEntities()) {
        //     auto ImageComponent = _componentManager->getDisplayComponentOfSpecifiedType(it->getID(),std::type_index(typeid(ecs::components::Image)));
        //     auto bruh = std::dynamic_pointer_cast<ecs::components::Image>(ImageComponent);
        //     std::cout << "show image " << std::endl;
        // }
    }
}