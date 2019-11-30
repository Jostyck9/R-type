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
#include "IEntityFactory.hpp"
#include "IManagerWrapper.hpp"

namespace ecs::system
{
    class SystemManager : public ISystemManager
    {
    private:
        std::shared_ptr<IManagerWrapper> _managerWrapper;
        std::shared_ptr<ecs::entities::IEntityFactory> _entityFactory;
        std::list<std::shared_ptr<ISystem>> _systems;
        std::list<int> _entitiesToDelete;

        /**
         * @brief Throw a SystemEsception if no entityFactcory was given
         * 
         */
        void checkIfEntityFactory();

    public:
        /**
         * @brief Construct a new System Manager object
         * 
         * @param entityManager 
         * @param componentManager 
         */
        SystemManager(std::shared_ptr<IManagerWrapper> managerWrapper);
        ~SystemManager();

        /**
         * @brief Get the Entities To Delete object
         * 
         * @return std::list<int>& 
         */
        std::list<int> &getEntitiesToDelete() override;

        SystemResponse updateAll() override;

        /**
         * @brief Add a system inside the system manager
         * 
         * @param system 
         */
        void addSystem(std::shared_ptr<ISystem> system) override;

        /**
         * @brief Delete all the systems inside the system manager
         * 
         */
        void deleteAll() override;

        /**
         * @brief Set the Entity Factory object, it's MANDATORY for using systemManager
         * 
         * @param entityFactory 
         */
        void setEntityFactory(std::shared_ptr<ecs::entities::IEntityFactory> entityFactory);
    };
}

#endif //SYSTEMMANGER_HPP__