/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** SystemFactory.hpp
*/

#ifndef SYSTEMFACTORY_HPP
#define SYSTEMFACTORY_HPP

#include <map>
#include "ISystemConstructor.hpp"
#include "ISystemFactory.hpp"
#include "IEntityManager.hpp"
#include "IComponentManager.hpp"
#include "ManagerWrapper.hpp"

namespace ecs::system
{
class SystemFactory : public ISystemFactory
{
private:
    std::shared_ptr<ManagerWrapper> _managerWrapper;
    std::shared_ptr<ISystemManager> _systemManager;
    std::map<std::string, std::shared_ptr<ISystemConstructor>> _createFunction;

public:
    /**
         * @brief Construct a new System Factory object
         * 
         * @param componentsManager : System manager
         */
    SystemFactory(std::shared_ptr<ManagerWrapper> &_managerWrapper, std::shared_ptr<ISystemManager>);
    ~SystemFactory();

    /**
         * @brief Create a System object by his name
         * 
         * @param name 
         * @return std::shared_ptr<ISystem> 
         */
    std::shared_ptr<ISystem> createSystem(const std::string &name) override;

    /**
         * @brief Add a System construtor that will be used in the system factory
         * 
         * @param contructor 
         */
    void addSystemConstructor(std::shared_ptr<ISystemConstructor> contructor) override;

    /**
         * @brief Check if an System Constructor exist
         * 
         * @param name 
         * @return true 
         * @return false 
         */
    bool isExisting(const std::string &name) override;

    /**
     * @brief Remove a system constructor
     * 
     * @param name 
     * @return true 
     * @return false 
     */
    bool remove(const std::string &name) override;

    /**
     * @brief Delete all systems factory
     * 
     */
    void deleteAll() override;
};
} // namespace ecs::system

#endif //SYSTEMFACTORY_HPP