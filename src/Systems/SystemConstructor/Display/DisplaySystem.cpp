/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** DisplaySystem.cpp
*/

#include <iostream>
#include "Position.hpp"
#include "Image.hpp"
#include "Physics/Position.hpp"
#include "Physics/Velocity.hpp"
#include "Display/Sprite.hpp"
#include "DisplaySystem.hpp"
#include "Collision.hpp"
#include "ComponentExceptions.hpp"
#include "SystemConstructor.hpp"

namespace ecs::system
{
DisplaySystem::DisplaySystem(std::shared_ptr<ManagerWrapper> &managerWrapper, std::shared_ptr<ecs::entities::IEntityFactory> &entityFactory, std::list<int> &entitiesToDelete) : ASystem(managerWrapper, entityFactory, entitiesToDelete), _elapsedTime(0)
{
}

DisplaySystem::~DisplaySystem()
{
}

SystemResponse DisplaySystem::update()
{
    std::shared_ptr<ecs::components::Sprite> spriteComp;
    std::shared_ptr<ecs::components::Position> posComp;
    std::shared_ptr<ecs::components::Text> textComp;

    _managerWrapper->getRenderManager()->clear();
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
            if (spriteComp->getIsVisible())
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
    _managerWrapper->getRenderManager()->display();
    return SystemResponse();
}

const std::string DisplaySystem::getName() const
{
    return ("Display");
}
} // namespace ecs::system

extern "C"
{
    ecs::system::ISystemConstructor *entryPoint()
    {
        return (new ecs::system::SystemConstructor<ecs::system::DisplaySystem>());
    }
}