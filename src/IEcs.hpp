/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** IEcs.hpp
*/

#ifndef IECS_HPP__
#define IECS_HPP__

#include "ResourceManager.hpp"
#include "ManagerWrapper.hpp"
#include "SystemManager.hpp"
#include "FactoriesWrapper.hpp"

namespace ecs
{
class IEcs
{
public:
    /**
     * @brief Get the Component Manager object
     * 
     * @return std::shared_ptr<components::IComponentManager>& 
     */
    virtual std::shared_ptr<components::IComponentManager> &getComponentManager() = 0;

    /**
     * @brief Get the Render Manager object
     * 
     * @return std::shared_ptr<IRenderManager>& 
     */
    virtual std::shared_ptr<IRenderManager> &getRenderManager() = 0;

    /**
     * @brief Get the Entity Manager object
     * 
     * @return std::shared_ptr<entities::IEntityManager>& 
     */
    virtual std::shared_ptr<entities::IEntityManager> &getEntityManager() = 0;

    /**
     * @brief Get the Rtype Resource Manager object
     * 
     * @return std::shared_ptr<RtypeResources>& 
     */
    virtual std::shared_ptr<ecs::ResourceManager> &getResourceManager() = 0;

    /**
     * @brief Get the System Manager object
     * 
     * @return std::shared_ptr<ecs::system::ISystemManager>& 
     */
    virtual std::shared_ptr<ecs::system::ISystemManager> &getSystemManager() = 0;

    /**
     * @brief Get the System Factory object
     * 
     * @return std::shared_ptr<ecs::system::ISystemFactory>& 
     */
    virtual std::shared_ptr<ecs::system::ISystemFactory> &getSystemFactory() = 0;

    /**
     * @brief Get the Entity Factory object
     * 
     * @return std::shared_ptr<ecs::entities::IEntityFactory>& 
     */
    virtual std::shared_ptr<ecs::entities::IEntityFactory> &getEntityFactory() = 0;

    /**
     * @brief Return the manager wrapper
     * 
     * @return std::shared_ptr<ecs::IManagerWrapper>& 
     */
    virtual std::shared_ptr<ecs::IManagerWrapper> &getManagerWrapper() = 0;
};

} // namespace ecs


#endif //IECS_HPP__