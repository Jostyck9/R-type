/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** EnnemiesMovementSystem.cpp
*/

#include <iostream>
#include "Physics/Velocity.hpp"
#include "ComponentExceptions.hpp"
#include "EnnemiesMovementSystem.hpp"

namespace ecs::system
{

EnnemiesMovementSystem::EnnemiesMovementSystem(std::shared_ptr<ManagerWrapper> &managerWrapper, std::shared_ptr<ecs::entities::IEntityFactory> &entityFactory, std::list<int> &entitiesToDelete) : ASystem(managerWrapper, entityFactory, entitiesToDelete)
{
}

SystemResponse EnnemiesMovementSystem::update()
{
    std::shared_ptr<ecs::components::Velocity> velocityComp;
    for (auto &it : _managerWrapper->getEntityManager()->getAllEntities())
    {
        try
        {
            std::dynamic_pointer_cast<ecs::components::EnnemiesController>(_managerWrapper->getComponentManager()->getGameLogicComponentOfSpecifiedType(it->getID(), std::type_index(typeid(ecs::components::EnnemiesController))));
            std::shared_ptr<ecs::components::EnnemiesController> controller = std::dynamic_pointer_cast<ecs::components::EnnemiesController>(_managerWrapper->getComponentManager()->getGameLogicComponentOfSpecifiedType(it->getID(), std::type_index(typeid(ecs::components::EnnemiesController))));
            velocityComp = std::dynamic_pointer_cast<ecs::components::Velocity>(_managerWrapper->getComponentManager()->getPhysicComponentOfSpecifiedType(it->getID(), std::type_index(typeid(ecs::components::Velocity))));
            updateVelocityOnPattern(controller, velocityComp);
        }
        catch (const ComponentExceptions &e)
        {           
        }
    }
    return SystemResponse();
}

void EnnemiesMovementSystem::updateVelocityOnPattern(std::shared_ptr<ecs::components::EnnemiesController> &controller, std::shared_ptr<ecs::components::Velocity> &velocityComp)
{
    // switch (controller->getShipType()) {
    //     case "Basic" :
    //         return;
    //     case "Wave" : 
            velocityComp->setVelocityY(50);
    //         break;
    //     case default:
    //         break;
    // }//clock 2 sec + check pattern via shipType
    // if ()
    //sinus pour avoi rl'offset ? mais pas envie de toucher au position donc jsp peut etre juste inverser les velocity toutes les 2 s
}
} // namespace ecs::system
