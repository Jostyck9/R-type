/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** ManagerWrapper.hpp
*/

#ifndef MANAGERWRAPPER_HPP__
#define MANAGERWRAPPER_HPP__

#include "IManagerWrapper.hpp"
#include "RtypeResources.hpp"

namespace ecs
{
class ManagerWrapper : public IManagerWrapper
{
private:

    std::shared_ptr<components::IComponentManager> _componentManager;
    std::shared_ptr<entities::IEntityManager> _entityManager;
    std::shared_ptr<ecs::ResourceManager> _rtypeResourceManager;
    std::shared_ptr<IRenderManager> _renderManager;


public:
    ManagerWrapper(/* args */);
    ~ManagerWrapper();
    std::shared_ptr<components::IComponentManager> &getComponentManager() override;
    std::shared_ptr<IRenderManager> &getRenderManager() override;
    std::shared_ptr<entities::IEntityManager> &getEntityManager() override;
    std::shared_ptr<ecs::ResourceManager> &getResourceManager() override;
};
} // namespace ecs

#endif //MANAGERWRAPPER_HPP__