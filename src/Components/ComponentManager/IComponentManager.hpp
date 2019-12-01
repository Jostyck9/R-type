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

namespace ecs::components
{
    /**
     * @brief Manage all the ecs::components of the game
     * 
     */
    class IComponentManager
    {
    public:
        /**
         * @brief Get the Physic Components from an entity by his id
         * 
         * @param idEntity 
         * @return std::list<std::shared_ptr<IComponent>> 
         */
        virtual std::list<std::shared_ptr<IComponent>> getPhysicComponents(size_t idEntity) = 0;

        /**
         * @brief Get a Physic Component of a specific type of an entityId
         * 
         * @param idEntity 
         * @param type
         * @return std::shared_ptr<IComponent>
         */
        virtual std::shared_ptr<IComponent> getPhysicComponentOfSpecifiedType(size_t idEntity, const std::type_index &type) = 0;

        /**
         * @brief Get the Physic Component object
         * 
         * @param entity
         * @return std::list<std::shared_ptr<IComponent>> 
         */
        virtual std::list<std::shared_ptr<IComponent>> getPhysicComponents(const std::shared_ptr<entities::Entity> &entity) = 0;
        
        /**
         * @brief Get a Physic Component of a specific type of an entity object
         * 
         * @param entity 
         * @param type
         * @return std::shared_ptr<IComponent>
         */
        virtual std::shared_ptr<IComponent> getPhysicComponentOfSpecifiedType(const std::shared_ptr<entities::Entity> &entity, const std::type_index &type) = 0;

        /**
         * @brief Get the Display Components from an entity by his id
         * 
         * @param idEntity 
         * @return std::list<std::shared_ptr<IComponent>> 
         */
        virtual std::list<std::shared_ptr<IComponent>> getDisplayComponents(size_t idEntity) = 0;

        /**
         * @brief Get a Display Component of a specific type of an entityId
         * 
         * @param idEntity 
         * @param type
         * @return std::shared_ptr<IComponent>
         */
        virtual std::shared_ptr<IComponent> getDisplayComponentOfSpecifiedType(size_t idEntity, const std::type_index &type) = 0;

        /**
         * @brief Get the Display Component object
         * 
         * @param entity 
         * @return std::list<std::shared_ptr<IComponent>> 
         */
        virtual std::list<std::shared_ptr<IComponent>> getDisplayComponents(const std::shared_ptr<entities::Entity> &entity) = 0;

        /**
         * @brief Get a Display Component of a specific type of an entity object
         * 
         * @param entity 
         * @param type
         * @return std::shared_ptr<IComponent>
         */
        virtual std::shared_ptr<IComponent> getDisplayComponentOfSpecifiedType(const std::shared_ptr<entities::Entity> &entity, const std::type_index &type) = 0;

        /**
         * @brief Get The IO Components from an entity by his id
         * 
         * @param idEntity 
         * @return std::list<std::shared_ptr<IComponent>> 
         */
        virtual std::list<std::shared_ptr<IComponent>> getIOComponents(size_t idEntity) = 0;

        /**
         * @brief Get a IO Component of a specific type of an entityId
         * 
         * @param idEntity 
         * @param type
         * @return std::shared_ptr<IComponent>
         */
        virtual std::shared_ptr<IComponent> getIOComponentOfSpecifiedType(size_t idEntity, const std::type_index &type) = 0;

        /**
         * @brief Get The IO Components from an entity
         * 
         * @param entity 
         * @return std::list<std::shared_ptr<IComponent>> 
         */
        virtual std::list<std::shared_ptr<IComponent>> getIOComponents(const std::shared_ptr<entities::Entity> &entity) = 0;

        /**
         * @brief Get an IO Component of a specific type of an entity object
         * 
         * @param entity 
         * @param type
         * @return std::shared_ptr<IComponent>
         */
        virtual std::shared_ptr<IComponent> getIOComponentOfSpecifiedType(const std::shared_ptr<entities::Entity> &entity, const std::type_index &type) = 0;

        /**
         * @brief Get the Game Logic Components from an entity by his id
         * 
         * @param idEntity 
         * @return std::list<std::shared_ptr<IComponent>> 
         */
        virtual std::list<std::shared_ptr<IComponent>> getGameLogicComponents(size_t idEntity) = 0;
     
        /**
         * @brief Get a GameLogic Component of a specific type of an entityId
         * 
         * @param idEntity 
         * @param type
         * @return std::shared_ptr<IComponent>
         */
        virtual std::shared_ptr<IComponent> getGameLogicComponentOfSpecifiedType(size_t idEntity, const std::type_index &type) = 0;

        /**
         * @brief Get the Game Logic Component object
         * 
         * @param entity 
         * @return std::list<std::shared_ptr<IComponent>> 
         */
        virtual std::list<std::shared_ptr<IComponent>> getGameLogicComponents(const std::shared_ptr<entities::Entity> &entity) = 0;

        /**
         * @brief Get a GameLogic Component of a specific type of an entity object
         * 
         * @param entity 
         * @param type
         * @return std::shared_ptr<IComponent>
         */
        virtual std::shared_ptr<IComponent> getGameLogicComponentOfSpecifiedType(const std::shared_ptr<entities::Entity> &entity, const std::type_index &type) = 0;

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
         * @brief Delete all the ecs::components from an entity
         * 
         * @param idEntity 
         */
        virtual void deleteComponents(size_t idEntity) = 0;

        /**
         * @brief Delete all the ecs::components from an entity
         * 
         * @param entity 
         */
        virtual void deleteComponents(const std::shared_ptr<entities::Entity> &entity) = 0;

        /**
         * @brief Delete all the components
         * 
         */
        virtual void deleteAllComponents() = 0;
    };
}

#endif //ICOMPONENTMANAGER_HPP_