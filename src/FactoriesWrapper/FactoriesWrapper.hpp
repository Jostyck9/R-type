/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** FactoriesWrapper.hpp
*/

#ifndef FACTORIESWRAPPER_HPP__
#define FACTORIESWRAPPER_HPP__

#include "SystemManager.hpp"
#include "ManagerWrapper.hpp"
#include "SystemFactory.hpp"
#include "EntityFactory.hpp"

namespace ecs
{

class FactoriesWrapper
{
private:
    std::shared_ptr<ecs::entities::IEntityFactory> _entityFactory;
    std::shared_ptr<ecs::system::ISystemFactory> _systemFactory;
public:
    FactoriesWrapper(
        std::shared_ptr<ManagerWrapper> &managerWrapper,
        std::shared_ptr<ecs::system::ISystemManager> &systemManager
        );
    ~FactoriesWrapper();

    /**
     * @brief Get the Entity Factory object
     * 
     * @return std::shared_ptr<ecs::entities::IEntityFactory>& 
     */
    std::shared_ptr<ecs::entities::IEntityFactory> &getEntityFactory();

    /**
     * @brief Get the System Factory object
     * 
     * @return std::shared_ptr<ecs::system::ISystemFactory>& 
     */
    std::shared_ptr<ecs::system::ISystemFactory> &getSystemFactory();
};

} // namespace ecs::

#endif //FACTORIESWRAPPER_HPP__