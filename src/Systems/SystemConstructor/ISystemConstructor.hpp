/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** ISystemConstructor.hpp
*/

#ifndef ISYSTEMCONSTRUCTOR_HPP
#define ISYSTEMCONSTRUCTOR_HPP

#include <memory>
#include <list>
#include <string>
#include "ISystem.hpp"
#include "ISystemManager.hpp"
#include "IComponentManager.hpp"
#include "IEntityManager.hpp"
#include "ManagerWrapper.hpp"

namespace ecs::system
{
class ISystemConstructor
{
private:
public:
     /**
     * @brief Create an ISystem associated with the class
     * 
     * @param systemManager
     * @param componentsManager
     * @return std::shared_ptr<ecs::system::ISystem> 
     */
    virtual std::shared_ptr<ecs::system::ISystem> create(std::shared_ptr<ManagerWrapper> &managerWrapper,
        std::list<int> &entitiesToDelete) = 0;
    /**
     * @brief Get the Name of the entity
     * 
     * @return std::string 
     */
    virtual std::string getName() = 0;
};

} // namespace ecs::system

#endif //ISYSTEMCONSTRUCTOR_HPP