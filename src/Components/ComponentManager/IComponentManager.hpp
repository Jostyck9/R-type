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
#include "Entity.hpp"

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
         * @return std::list<std::reference_wrapper<std::shared_ptr<IComponent>>> 
         */
        virtual std::list<std::reference_wrapper<std::shared_ptr<IComponent>>> getPhysicComponents(size_t idEntity) = 0;

        /**
         * @brief Get the Physic Component object
         * 
         * @param entity
         * @return std::list<std::reference_wrapper<std::shared_ptr<IComponent>>> 
         */
        virtual std::list<std::reference_wrapper<std::shared_ptr<IComponent>>> getPhysicComponents(const std::shared_ptr<entities::Entity> &entity) = 0;

        /**
         * @brief Get the Display Components from an entity by his id
         * 
         * @param idEntity 
         * @return std::list<std::reference_wrapper<std::shared_ptr<IComponent>>> 
         */
        virtual std::list<std::reference_wrapper<std::shared_ptr<IComponent>>> getDisplayComponents(size_t idEntity) = 0;

        /**
         * @brief Get the Display Component object
         * 
         * @param entity 
         * @return std::list<std::reference_wrapper<std::shared_ptr<IComponent>>> 
         */
        virtual std::list<std::reference_wrapper<std::shared_ptr<IComponent>>> getDisplayComponents(const std::shared_ptr<entities::Entity> &entity) = 0;

        /**
         * @brief Get The IO Components from an entity by his id
         * 
         * @param idEntity 
         * @return std::list<std::reference_wrapper<std::shared_ptr<IComponent>>> 
         */
        virtual std::list<std::reference_wrapper<std::shared_ptr<IComponent>>> getIOComponents(size_t idEntity) = 0;

        /**
         * @brief Get The IO Components from an entity
         * 
         * @param entity 
         * @return std::list<std::reference_wrapper<std::shared_ptr<IComponent>>> 
         */
        virtual std::list<std::reference_wrapper<std::shared_ptr<IComponent>>> getIOComponents(const std::shared_ptr<entities::Entity> &entity) = 0;

        /**
         * @brief Get the Game Logic Components from an entity by his id
         * 
         * @param idEntity 
         * @return std::list<std::reference_wrapper<std::shared_ptr<IComponent>>> 
         */
        virtual std::list<std::reference_wrapper<std::shared_ptr<IComponent>>> getGameLogicComponents(size_t idEntity) = 0;

        /**
         * @brief Get the Game Logic Component object
         * 
         * @param entity 
         * @return std::list<std::reference_wrapper<std::shared_ptr<IComponent>>> 
         */
        virtual std::list<std::reference_wrapper<std::shared_ptr<IComponent>>> getGameLogicComponents(const std::shared_ptr<entities::Entity> &entity) = 0;

        /**
         * @brief Add a Physic Component object
         * 
         * @param component 
         * @param idEntity
         */
        virtual void addPhysicComponent(std::shared_ptr<IComponent> component, size_t idEntity) = 0;

        /**
         * @brief Add a Physic Component object
         * 
         * @param component 
         * @param entity 
         */
        virtual void addPhysicComponent(std::shared_ptr<IComponent> component, const std::shared_ptr<entities::Entity> &entity) = 0;

        /**
         * @brief Add a Display Component object
         * 
         * @param component 
         * @param idEntity
         */
        virtual void addDisplayComponent(std::shared_ptr<IComponent> component, size_t idEntity) = 0;

        /**
         * @brief Add a Display Component object
         * 
         * @param component 
         * @param entity 
         */
        virtual void addDisplayComponent(std::shared_ptr<IComponent> component, const std::shared_ptr<entities::Entity> &entity) = 0;

        /**
         * @brief Add a IO component object
         * 
         * @param component
         * @param idEntity
         */
        virtual void addIOComponent(std::shared_ptr<IComponent> component, size_t idEntity) = 0;

        /**
         * @brief Add a IO component object
         * 
         * @param component 
         * @param entity 
         */
        virtual void addIOComponent(std::shared_ptr<IComponent> component, const std::shared_ptr<entities::Entity> &entity) = 0;

        /**
         * @brief Add a Game Logic Component object
         * 
         * @param component 
         * @param idEntity
         */
        virtual void addGameLogicComponent(std::shared_ptr<IComponent> component, size_t idEntity) = 0;

        /**
         * @brief Add a Game Logic Component object
         * 
         * @param component 
         * @param entity 
         */
        virtual void addGameLogicComponent(std::shared_ptr<IComponent> component, const std::shared_ptr<entities::Entity> &entity) = 0;

        /**
         * @brief Remove all the components from an entity
         * 
         * @param idEntity 
         */
        virtual void removeComponents(size_t idEntity) = 0;
    };
}

#endif //ICOMPONENTMANAGER_HPP_