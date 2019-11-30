/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Ecs.cpp
*/

#include "Ecs.hpp"

using namespace ecs;

Ecs::Ecs(/* args */) : _managerWrapper(std::make_shared<ecs::ManagerWrapper>()),
                       _systemManager(std::reinterpret_pointer_cast<ecs::system::ISystemManager>(std::make_shared<ecs::system::SystemManager>(_managerWrapper))),
                       _factoriesWrapper(std::make_shared<ecs::FactoriesWrapper>(_managerWrapper, _systemManager))
{
    _systemManager->setEntityFactory(_factoriesWrapper->getEntityFactory());
}

Ecs::~Ecs()
{
}

std::shared_ptr<components::IComponentManager> &Ecs::getComponentManager()
{
    return _managerWrapper->getComponentManager();
}

std::shared_ptr<IRenderManager> &Ecs::getRenderManager()
{
    return _managerWrapper->getRenderManager();
}

std::shared_ptr<entities::IEntityManager> &Ecs::getEntityManager()
{
    return _managerWrapper->getEntityManager();
}

std::shared_ptr<ecs::ResourceManager> &Ecs::getResourceManager()
{
    return _managerWrapper->getRtypeResourceManager();
}

std::shared_ptr<ecs::system::ISystemManager> &Ecs::getSystemManager()
{
    return _systemManager;
}

std::shared_ptr<ecs::system::ISystemFactory> &Ecs::getSystemFactory()
{
    return _factoriesWrapper->getSystemFactory();
}

std::shared_ptr<ecs::entities::IEntityFactory> &Ecs::getEntityFactory()
{
    return _factoriesWrapper->getEntityFactory();
}

std::shared_ptr<ecs::ManagerWrapper> &Ecs::getManagerWrapper()
{
    return _managerWrapper;
}