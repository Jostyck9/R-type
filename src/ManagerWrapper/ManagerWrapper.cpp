/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** ManagerWrapper.cpp
*/

#include "ManagerWrapper.hpp"

namespace ecs
{
ManagerWrapper::ManagerWrapper(/* args */) : _componentManager(std::make_shared<ComponentManager>()),
                                             _entityManager(std::make_shared<ecs::EntityManager>(_componentManager)),
                                             _renderManager(std::make_shared<ecs::SFMLRenderManager>())
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
    return this->_componentManager;
}
} // namespace ecs