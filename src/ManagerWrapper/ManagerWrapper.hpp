/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** ManagerWrapper.hpp
*/

#ifndef MANAGERWRAPPER_HPP__
#define MANAGERWRAPPER_HPP__

#include "IRenderManager.hpp"
#include "IEntityManager.hpp"
#include "ISystemManager.hpp"
#include "IComponentManager.hpp"
#include "RtypeResources.hpp"

namespace ecs
{
class ManagerWrapper
{
private:

    std::shared_ptr<components::IComponentManager> _componentManager;
    std::shared_ptr<entities::IEntityManager> _entityManager;
    std::shared_ptr<RtypeResources> _rtypeResourceManager;
    std::shared_ptr<IRenderManager> _renderManager;


public:
    ManagerWrapper(/* args */);
    ~ManagerWrapper();
    std::shared_ptr<components::IComponentManager> &getComponentManager();
    std::shared_ptr<IRenderManager> &getRenderManager();
    std::shared_ptr<entities::IEntityManager> &getEntityManager();
    std::shared_ptr<RtypeResources> &getRtypeResourceManager();

};
} // namespace ecs

#endif //MANAGERWRAPPER_HPP__