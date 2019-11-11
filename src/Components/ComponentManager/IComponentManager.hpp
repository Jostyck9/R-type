/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** IComponentManager.hpp
*/

#ifndef ICOMPONENTMANAGER_HPP_
#define ICOMPONENTMANAGER_HPP_

#include <list>
#include <memory>
#include "IComponent.hpp"

namespace components
{
    /**
     * @brief Manage all the components of the game
     * 
     */
    class IComponentManager
    {
    public:
        /**
         * @brief Get the Physic Components from an entity by his id
         * 
         * @param idEntity 
         * @return std::list<std::shared_ptr<IComponent>&> 
         */
        virtual std::list<std::reference_wrapper<std::shared_ptr<IComponent>>> getPhysicComponent(size_t idEntity) = 0;

        /**
         * @brief Get the Display Components from an entity by his id
         * 
         * @param idEntity 
         * @return std::list<std::shared_ptr<IComponent>&> 
         */
        virtual std::list<std::reference_wrapper<std::shared_ptr<IComponent>>> getDisplayComponent(size_t idEntity) = 0;

        /**
         * @brief Get The IO Components from an entity by his id
         * 
         * @param idEntity 
         * @return std::list<std::shared_ptr<IComponent>&> 
         */
        virtual std::list<std::reference_wrapper<std::shared_ptr<IComponent>>> getIOComponent(size_t idEntity) = 0;

        /**
         * @brief Get the Network Components from an entity by his id
         * 
         * @param idEntity 
         * @return std::list<std::shared_ptr<IComponent>&> 
         */
        virtual std::list<std::reference_wrapper<std::shared_ptr<IComponent>>> getNetworkComponent(size_t idEntity) = 0;

        /**
         * @brief Get the Game Logic Components from an entity by his id
         * 
         * @param idEntity 
         * @return std::list<std::shared_ptr<IComponent>&> 
         */
        virtual std::list<std::reference_wrapper<std::shared_ptr<IComponent>>> getGameLogicComponent(size_t idEntity) = 0;

        /**
         * @brief Add a Physic Component object
         * 
         * @param component 
         */
        virtual void addPhysicComponent(std::shared_ptr<IComponent> component, size_t idEntity) = 0;

        /**
         * @brief Add a Display Component object
         * 
         * @param component 
         */
        virtual void addDisplayComponent(std::shared_ptr<IComponent> component, size_t idEntity) = 0;

        /**
         * @brief Add a IO component object
         * 
         * @param component 
         */
        virtual void addIOComponent(std::shared_ptr<IComponent> component, size_t idEntity) = 0;

        /**
         * @brief Add a Network Component object
         * 
         * @param component 
         */
        virtual void addNetworkComponent(std::shared_ptr<IComponent> component, size_t idEntity) = 0;

        /**
         * @brief Add a Game Logic Component object
         * 
         * @param component 
         */
        virtual void addGameLogicComponent(std::shared_ptr<IComponent> component, size_t idEntity) = 0;

        /**
         * @brief Remove all the components from an entity
         * 
         * @param idEntity 
         */
        virtual void removeComponent(size_t idEntity) = 0;
    };
}

#endif //ICOMPONENTMANAGER_HPP_