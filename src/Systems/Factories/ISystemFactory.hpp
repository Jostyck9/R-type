/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** ISystemFactory.hpp
*/

#ifndef SYSTEMFACTORY_HPP__
#define SYSTEMFACTORY_HPP__

#include <string>
#include <memory>
#include "ISystemConstructor.hpp"
#include "ISystem.hpp"

namespace ecs::system
{

class ISystemFactory
{
private:
public:
    /**
     * @brief Create an ISystem object with the specific name
     * 
     * @param name 
     * @return std::shared_ptr<ISystem> 
     */
    virtual std::shared_ptr<ISystem> createSystem(const std::string &name) = 0;

    /**
     * @brief Add an systemConstructor to use inside the factory
     * 
     * @param constructor 
     */
    virtual void addSystemConstructor(std::shared_ptr<ISystemConstructor>) = 0;

    /**
     * @brief Check if an System Constructor exist
     * 
     * @param name 
     * @return true 
     * @return false 
     */
    virtual bool isExisting(const std::string &name) = 0;

    /**
     * @brief Remove a system constructor
     * 
     * @param name 
     * @return true 
     * @return false 
     */
    virtual bool remove(const std::string &name) = 0;

    /**
     * @brief Delete all systems factory
     * 
     */
    virtual void deleteAll() = 0;
};
}// namespace ecs::system

#endif // SYSTEMFACTORY_HPP__