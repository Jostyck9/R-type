/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Ecs.hpp
*/

#ifndef ECS_HPP__
#define ECS_HPP__

#include "IEcs.hpp"

namespace ecs
{
class Ecs : public IEcs
{
private:
    std::shared_ptr<IManagerWrapper> _managerWrapper;
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
    std::shared_ptr<components::IComponentManager> &getComponentManager() override;

    /**
     * @brief Get the Render Manager object
     * 
     * @return std::shared_ptr<IRenderManager>& 
     */
    std::shared_ptr<IRenderManager> &getRenderManager() override;

    /**
     * @brief Get the Entity Manager object
     * 
     * @return std::shared_ptr<entities::IEntityManager>& 
     */
    std::shared_ptr<entities::IEntityManager> &getEntityManager() override;

    /**
     * @brief Get the Rtype Resource Manager object
     * 
     * @return std::shared_ptr<RtypeResources>& 
     */
    std::shared_ptr<ecs::ResourceManager> &getResourceManager() override;

    /**
     * @brief Get the System Manager object
     * 
     * @return std::shared_ptr<ecs::system::ISystemManager>& 
     */
    std::shared_ptr<ecs::system::ISystemManager> &getSystemManager() override;

    /**
     * @brief Get the System Factory object
     * 
     * @return std::shared_ptr<ecs::system::ISystemFactory>& 
     */
    std::shared_ptr<ecs::system::ISystemFactory> &getSystemFactory() override;

    /**
     * @brief Get the Entity Factory object
     * 
     * @return std::shared_ptr<ecs::entities::IEntityFactory>& 
     */
    std::shared_ptr<ecs::entities::IEntityFactory> &getEntityFactory() override;

    /**
     * @brief Return the manager wrapper
     * 
     * @return std::shared_ptr<ecs::IManagerWrapper>& 
     */
    std::shared_ptr<ecs::IManagerWrapper> &getManagerWrapper() override;
};

} // namespace ecs

#endif //ECS_HPP__