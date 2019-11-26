/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** DisplaySystem.cpp
*/

#include <iostream>
#include "Physics/Position.hpp"
#include "Physics/Velocity.hpp"
#include "Display/Sprite.hpp"
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
        for (auto &it :  _managerWrapper->getEntityManager()->getAllEntities()) {
            // auto spriteComp = _managerWrapper->getComponentManager()->getDisplayComponentOfSpecifiedType(it->getID(),std::type_index(typeid(ecs::components::Sprite)));
             _managerWrapper->getRenderManager()->graphicsUpdate();
        }
    }
}