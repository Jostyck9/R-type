/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** ASystem.cpp
*/

#include "ASystem.hpp"

namespace ecs::system
{
    ASystem::ASystem(std::shared_ptr<entities::IEntityManager> &entityManager, std::shared_ptr<components::IComponentManager> &componentManager, std::list<int> &entitiesToDelete) :
    _entityManager(entityManager),
    _componentManager(componentManager),
    _entitiesToDelete(entitiesToDelete)
    {
    }

    ASystem::~ASystem()
    {
    }
}