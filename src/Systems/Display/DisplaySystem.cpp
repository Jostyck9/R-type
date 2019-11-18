/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** DisplaySystem.cpp
*/

#include "DisplaySystem.hpp"
#include <iostream>

namespace ecs::system
{
    DisplaySystem::DisplaySystem(std::shared_ptr<entities::IEntityManager> &entityManager, std::shared_ptr<components::IComponentManager> &componentManager, std::list<int> &entitiesToDelete) : 
    ASystem(entityManager, componentManager, entitiesToDelete)
    {
    }
    
    DisplaySystem::~DisplaySystem()
    {
    }

    void DisplaySystem::update()
    {
        std::cout << "Update Display" << std::endl;
    }
}