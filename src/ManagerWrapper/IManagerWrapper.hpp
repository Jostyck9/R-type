/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** IManagerWrapper.hpp
*/

#ifndef IMANAGER_WRAPPER_HPP_
#define IMANAGER_WRAPPER_HPP_

#include "IRenderManager.hpp"
#include "IEntityManager.hpp"
#include "ISystemManager.hpp"
#include "IComponentManager.hpp"
#include "ResourceManager.hpp"
#include <memory>

namespace ecs
{

class IManagerWrapper
{
public:
    virtual std::shared_ptr<components::IComponentManager> &getComponentManager() = 0;
    virtual std::shared_ptr<IRenderManager> &getRenderManager() = 0;
    virtual std::shared_ptr<entities::IEntityManager> &getEntityManager() = 0;
    virtual std::shared_ptr<ecs::ResourceManager> &getResourceManager() = 0;
};

} // namespace ecs

#endif //IMANAGER_WRAPPER_HPP_