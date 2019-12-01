/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** AnimationSystem.cpp
*/

#include <iostream>
#include "Animator.hpp"
#include "Sprite.hpp"
#include "ComponentExceptions.hpp"
#include "AnimationSystem.hpp"
#include "SystemConstructor.hpp"

namespace ecs::system
{

AnimationSystem::AnimationSystem(std::shared_ptr<ManagerWrapper> &managerWrapper, std::shared_ptr<ecs::entities::IEntityFactory> &entityFactory, std::list<int> &entitiesToDelete) : ASystem(managerWrapper, entityFactory, entitiesToDelete)
{
}

SystemResponse AnimationSystem::update()
{
    std::shared_ptr<ecs::components::Animator> animatorComp;
    std::shared_ptr<ecs::components::Sprite> spriteComp;
    Rect rect(0,0,0,0);
    for (auto &it : _managerWrapper->getEntityManager()->getAllEntities())
    {
        try
        {
            animatorComp = std::dynamic_pointer_cast<ecs::components::Animator>(_managerWrapper->getComponentManager()->getDisplayComponentOfSpecifiedType(it->getID(), std::type_index(typeid(ecs::components::Animator))));
            if (animatorComp->getTimer().getElapsedSeconds() < animatorComp->getInterval()) {
                continue;
            }
            
            rect = animatorComp->getRect();
            if (animatorComp->getCurrentRep() < animatorComp->getMaxRep()) {
                spriteComp = std::dynamic_pointer_cast<ecs::components::Sprite>(_managerWrapper->getComponentManager()->getDisplayComponentOfSpecifiedType(it->getID(), std::type_index(typeid(ecs::components::Sprite))));
                rect.setPosX(spriteComp->getRect().getPosX() + rect.getWidth());
                spriteComp->setRect(rect);
                animatorComp->setCurrentRep(animatorComp->getCurrentRep() + 1);
            }
            else {
                spriteComp = std::dynamic_pointer_cast<ecs::components::Sprite>(_managerWrapper->getComponentManager()->getDisplayComponentOfSpecifiedType(it->getID(), std::type_index(typeid(ecs::components::Sprite))));
                spriteComp->setRect(rect);
                animatorComp->setCurrentRep(0);
            }
            animatorComp->getTimer().restart();
        }
        catch (const ComponentExceptions &e)
        {
        }
    }
    return SystemResponse();
}

const std::string AnimationSystem::getName() const
{
    return ("Animation");
}

extern "C"
{
    ecs::system::ISystemConstructor *entryPoint()
    {
        return (new ecs::system::SystemConstructor<ecs::system::AnimationSystem>());
    }
}

}

