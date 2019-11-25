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
#include "IComponentManager.hpp"
#include "IEntityManager.hpp"
#include "ISystem.hpp"
#include "ISystemManager.hpp"
#include "IRenderManager.hpp"

namespace ecs::system
{
    class SystemManager : public ISystemManager
    {
    private:
        std::list<std::shared_ptr<ISystem>> _systems;
        std::list<int> _entitiesToDelete;
        std::shared_ptr<entities::IEntityManager> &_entityManager;
        std::shared_ptr<ecs::components::IComponentManager> &_componentManager;
        IRenderManager *_renderManager;

    public:
        /**
         * @brief Construct a new System Manager object
         * 
         * @param entityManager 
         * @param componentManager 
         */
        SystemManager(std::shared_ptr<entities::IEntityManager> &entityManager, std::shared_ptr<ecs::components::IComponentManager> &componentManager);
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
        
        /**
         * @brief Add a system inside the system manager
         * 
         * @param renderManager 
         */
        void setRenderManager(IRenderManager *renderManager);
    };
}

#endif //SYSTEMMANGER_HPP__