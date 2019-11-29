/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Ecs.hpp
*/

#ifndef ECS_HPP__
#define ECS_HPP__

#include "ResourceManager.hpp"
#include "ManagerWrapper.hpp"
#include "SystemManager.hpp"
#include "FactoriesWrapper.hpp"

namespace ecs
{
class Ecs
{
private:
    std::shared_ptr<ManagerWrapper> _managerWrapper;
    std::shared_ptr<ecs::system::ISystemManager> _systemManager;
    std::shared_ptr<ecs::FactoriesWrapper> _factoriesWrapper;

public:
    Ecs(/* args */);
    ~Ecs();

    /**
     * @brief Get the Component Manager object
     * 
     * @return std::shared_ptr<components::IComponentManager>& 
     */
    std::shared_ptr<components::IComponentManager> &getComponentManager();

    /**
     * @brief Get the Render Manager object
     * 
     * @return std::shared_ptr<IRenderManager>& 
     */
    std::shared_ptr<IRenderManager> &getRenderManager();

    /**
     * @brief Get the Entity Manager object
     * 
     * @return std::shared_ptr<entities::IEntityManager>& 
     */
    std::shared_ptr<entities::IEntityManager> &getEntityManager();

    /**
     * @brief Get the Rtype Resource Manager object
     * 
     * @return std::shared_ptr<RtypeResources>& 
     */
    std::shared_ptr<ecs::ResourceManager> &getResourceManager();

    /**
     * @brief Get the System Manager object
     * 
     * @return std::shared_ptr<ecs::system::ISystemManager>& 
     */
    std::shared_ptr<ecs::system::ISystemManager> &getSystemManager();

    /**
     * @brief Get the System Factory object
     * 
     * @return std::shared_ptr<ecs::system::ISystemFactory>& 
     */
    std::shared_ptr<ecs::system::ISystemFactory> &getSystemFactory();

    std::shared_ptr<ecs::entities::IEntityFactory> &getEntityFactory();
};

} // namespace ecs

#endif //ECS_HPP__