/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** ManagerWrapper.cpp
*/

#include "ManagerWrapper.hpp"
#include "SFMLRenderManager.hpp"

namespace ecs
{
ManagerWrapper::ManagerWrapper(/* args */) : _componentManager(std::make_shared<ecs::components::ComponentManager>()),
                                             _entityManager(std::make_shared<ecs::entities::EntityManager>(_componentManager)),
                                             _rtypeResourceManager(std::make_shared<ecs::RtypeResources>()),
                                             _renderManager(std::make_shared<ecs::SFMLRenderManager>(_rtypeResourceManager))
{
}

ManagerWrapper::~ManagerWrapper()
{
}

std::shared_ptr<components::IComponentManager> &ManagerWrapper::getComponentManager()
{
    return this->_componentManager;
}
std::shared_ptr<IRenderManager> &ManagerWrapper::getRenderManager()
{
    return this->_renderManager;
}
std::shared_ptr<entities::IEntityManager> &ManagerWrapper::getEntityManager()
{
    return this->_entityManager;
}

std::shared_ptr<ecs::ResourceManager> &ManagerWrapper::getResourceManager()
{
    return this->_rtypeResourceManager;
}

} // namespace ecs