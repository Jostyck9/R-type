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
DisplaySystem::DisplaySystem(std::shared_ptr<ManagerWrapper> &managerWrapper, std::list<int> &entitiesToDelete) : ASystem(managerWrapper, entitiesToDelete), _elapsedTime(0)
{
}

DisplaySystem::~DisplaySystem()
{
}

void DisplaySystem::update()
{
    std::shared_ptr<ecs::components::Sprite> spriteComp;
    std::shared_ptr<ecs::components::Position> posComp;
    std::shared_ptr<ecs::components::Text> textComp;

    for (auto &it : _managerWrapper->getEntityManager()->getAllEntities())
    {
        try
        {
            posComp = std::dynamic_pointer_cast<ecs::components::Position>(_managerWrapper->getComponentManager()->getPhysicComponentOfSpecifiedType(it->getID(), std::type_index(typeid(ecs::components::Position))));
        }
        catch (const ComponentExceptions &e)
        {
            continue;
        }
        try
        {
            spriteComp = std::dynamic_pointer_cast<ecs::components::Sprite>(_managerWrapper->getComponentManager()->getDisplayComponentOfSpecifiedType(it->getID(), std::type_index(typeid(ecs::components::Sprite))));
            _managerWrapper->getRenderManager()->graphicsUpdate(spriteComp, posComp);
        }
        catch (const ComponentExceptions &e)
        {
        }
        try
        {
            textComp = std::dynamic_pointer_cast<ecs::components::Text>(_managerWrapper->getComponentManager()->getDisplayComponentOfSpecifiedType(it->getID(), std::type_index(typeid(ecs::components::Text))));
            _managerWrapper->getRenderManager()->textUpdate(textComp, posComp);
        }
        catch (const ComponentExceptions &e)
        {
        }
    }
}
} // namespace ecs::system
