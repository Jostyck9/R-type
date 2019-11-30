/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** ASystem.cpp
*/

#include "ASystem.hpp"

namespace ecs::system
{
ASystem::ASystem(std::shared_ptr<ManagerWrapper> &managerWrapper,
                 std::shared_ptr<ecs::entities::IEntityFactory> &entityFactory,
                 std::list<int> &entitiesToDelete) : _managerWrapper(managerWrapper),
                                                     _entityFactory(entityFactory),
                                                     _entitiesToDelete(entitiesToDelete)
{
}

ASystem::~ASystem()
{
}
} // namespace ecs::system