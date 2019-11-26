/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** SystemManager.hpp
*/

#ifndef SYSTEMMANGER_HPP__
#define SYSTEMMANGER_HPP__

#include <memory>
#include <list>
#include "ISystem.hpp"
#include "ISystemManager.hpp"
#include "ManagerWrapper.hpp"

namespace ecs::system
{
    class SystemManager : public ISystemManager
    {
    private:
        std::shared_ptr<ManagerWrapper> _managerWrapper;
        std::list<std::shared_ptr<ISystem>> _systems;
        std::list<int> _entitiesToDelete;

    public:
        /**
         * @brief Construct a new System Manager object
         * 
         * @param entityManager 
         * @param componentManager 
         */
        SystemManager(std::shared_ptr<ManagerWrapper> managerWrapper);
        ~SystemManager();

        /**
         * @brief Get the Entities To Delete object
         * 
         * @return std::list<int>& 
         */
        std::list<int> &getEntitiesToDelete() override;

        void updateAll() override;

        /**
         * @brief Add a system inside the system manager
         * 
         * @param system 
         */
        void addSystem(std::shared_ptr<ISystem> system);
    };
}

#endif //SYSTEMMANGER_HPP__