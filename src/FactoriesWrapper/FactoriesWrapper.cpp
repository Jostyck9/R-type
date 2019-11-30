/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** FactoriesWrapper.cpp
*/

#include "FactoriesWrapper.hpp"

namespace ecs
{

FactoriesWrapper::FactoriesWrapper(
    std::shared_ptr<ManagerWrapper> &managerWrapper,
    std::shared_ptr<ecs::system::ISystemManager> &systemManager) : _entityFactory(std::make_shared<ecs::entities::EntityFactory>(managerWrapper->getEntityManager(), managerWrapper->getComponentManager())),
                                                                   _systemFactory(std::make_shared<ecs::system::SystemFactory>(managerWrapper, _entityFactory, systemManager))
{
}

FactoriesWrapper::~FactoriesWrapper()
{
}

std::shared_ptr<ecs::system::ISystemFactory> &FactoriesWrapper::getSystemFactory()
{
    return _systemFactory;
}

std::shared_ptr<ecs::entities::IEntityFactory> &FactoriesWrapper::getEntityFactory()
{
    return _entityFactory;
}

} // namespace ecs