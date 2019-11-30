/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** ParallaxSystem.cpp
*/

#include <iostream>
#include "Parallax.hpp"
#include "Sprite.hpp"
#include "ComponentExceptions.hpp"
#include "ParallaxSystem.hpp"

namespace ecs::system
{

ParallaxSystem::ParallaxSystem(std::shared_ptr<IManagerWrapper> &managerWrapper, std::shared_ptr<ecs::entities::IEntityFactory> &entityFactory, std::list<int> &entitiesToDelete) : ASystem(managerWrapper, entityFactory, entitiesToDelete)
{
}

SystemResponse ParallaxSystem::update()
{
    std::shared_ptr<ecs::components::Parallax> parallaxComp;
    std::shared_ptr<ecs::components::Sprite> spriteComp;
    Rect rect(0,0,0,0);
    for (auto &it : _managerWrapper->getEntityManager()->getAllEntities())
    {
        try
        {
            parallaxComp = std::dynamic_pointer_cast<ecs::components::Parallax>(_managerWrapper->getComponentManager()->getDisplayComponentOfSpecifiedType(it->getID(), std::type_index(typeid(ecs::components::Parallax))));
            if (parallaxComp->getTimer().getElapsedSeconds() < parallaxComp->getInterval()) {
                continue;
            }
            spriteComp = std::dynamic_pointer_cast<ecs::components::Sprite>(_managerWrapper->getComponentManager()->getDisplayComponentOfSpecifiedType(it->getID(), std::type_index(typeid(ecs::components::Sprite))));
            if (spriteComp->getRect().getPosX() <= (parallaxComp->getOffset() - parallaxComp->getMove())) {
                rect.setHeight(spriteComp->getRect().getHeight());
                rect.setWidth(spriteComp->getRect().getWidth());
                rect.setPosY(spriteComp->getRect().getPosY());
                rect.setPosX(spriteComp->getRect().getPosX() + parallaxComp->getMove());
                spriteComp->setRect(rect);
            }
            else {
                rect.setHeight(spriteComp->getRect().getHeight());
                rect.setWidth(spriteComp->getRect().getWidth());
                rect.setPosY(spriteComp->getRect().getPosY());
                rect.setPosX(parallaxComp->getRect().getPosX());
                spriteComp->setRect(rect);
            }
            parallaxComp->getTimer().restart();
        }
        catch (const ComponentExceptions &e)
        {
        }
    }
    return SystemResponse();
}
}