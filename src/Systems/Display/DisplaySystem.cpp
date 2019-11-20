/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** DisplaySystem.cpp
*/

#include "Physics/Position.hpp"
#include "Physics/Velocity.hpp"
#include "DisplaySystem.hpp"
#include <iostream>

namespace ecs::system
{
    DisplaySystem::DisplaySystem(std::shared_ptr<entities::IEntityManager> &entityManager, std::shared_ptr<ecs::components::IComponentManager> &componentManager, std::list<int> &entitiesToDelete) : 
    ASystem(entityManager, componentManager, entitiesToDelete)
    {
    }
    
    DisplaySystem::~DisplaySystem()
    {
    }

    void DisplaySystem::update()
    {
        std::cout << "On affiche des trucs à l'écran :) + on devrait update tout le monde" << std::endl;
    }
}