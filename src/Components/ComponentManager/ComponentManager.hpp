/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** ComponentManager.hpp
*/

#ifndef COMPONENTMANAGER_HPP_
#define COMPONENTMANAGER_HPP_

#include <map>
#include <memory>
#include "IComponent.hpp"
#include "IComponentManager.hpp"

namespace ecs::components
{
    /**
     * @brief Manage all the ecs::components of the game
     * 
     */
    class ComponentManager : public IComponentManager
    {
    private:
        std::multimap<size_t, std::shared_ptr<IComponent>> _physic;
        std::multimap<size_t, std::shared_ptr<IComponent>> _display;
        std::multimap<size_t, std::shared_ptr<IComponent>> _io;
        std::multimap<size_t, std::shared_ptr<IComponent>> _gameLogic;

        typedef std::multimap<size_t, std::shared_ptr<IComponent>>::iterator MMAPIterator;

        /**
         * @brief Extract the ecs::components from the map given with the idEntity
         * 
         * @param map 
         * @param idEntity 
         * @return std::list<std::shared_ptr<IComponent>> 
         */
        std::list<std::shared_ptr<IComponent>> extractComponentsFrom(std::multimap<size_t, std::shared_ptr<IComponent>> &map, size_t idEntity);
        /**
         * @brief Extract the ecs::components from the map given with the Type
         * 
         * @param map 
         * @param idEntity 
         * @param type 
         * @return std::shared_ptr<IComponent> 
         */
        std::shared_ptr<IComponent> extractComponentsOfType(std::multimap<size_t, std::shared_ptr<IComponent>> &map, size_t idEntity, const std::type_index type);

    public:
        ComponentManager();
        ~ComponentManager();

        /**
         * @brief Get the Physic Components from an entity by his id 
         * 
         * @param idEntity 
         * @return std::list<std::shared_ptr<IComponent>> 
         */
        std::list<std::shared_ptr<IComponent>> getPhysicComponents(size_t idEntity) override;

        /**
         * @brief Get the Physic Components of a specific type of an entityId
         * 
         * @param idEntity 
         * @param type
         * @return std::shared_ptr<IComponent>
         */
        std::shared_ptr<IComponent> getPhysicComponentOfSpecifiedType(size_t idEntity, const std::type_index &type) override;

        /**
         * @brief Get the Physic Component object
         * 
         * @param entity
         * @return std::list<std::shared_ptr<IComponent>> 
         */
        std::list<std::shared_ptr<IComponent>> getPhysicComponents(const std::shared_ptr<entities::Entity> &entity) override;

         /**
         * @brief Get the Physic Components of a specific type of an entity object
         * 
         * @param entity 
         * @param type
         * @return std::shared_ptr<IComponent>
         */
        std::shared_ptr<IComponent> getPhysicComponentOfSpecifiedType(const std::shared_ptr<entities::Entity> &entity, const std::type_index &type) override;

        /**
         * @brief Get the Display Components from an entity by his id
         * 
         * @param idEntity 
         * @return std::list<std::shared_ptr<IComponent>> 
         */
        std::list<std::shared_ptr<IComponent>> getDisplayComponents(size_t idEntity) override;

        /**
         * @brief Get a Display Component of a specific type of an entityId
         * 
         * @param idEntity 
         * @param type
         * @return std::shared_ptr<IComponent>
         */
        std::shared_ptr<IComponent> getDisplayComponentOfSpecifiedType(size_t idEntity, const std::type_index &type) override;

        /**
         * @brief Get the Display Component object
         * 
         * @param entity 
         * @return std::list<std::shared_ptr<IComponent>> 
         */
        std::list<std::shared_ptr<IComponent>> getDisplayComponents(const std::shared_ptr<entities::Entity> &entity) override;

        /**
         * @brief Get a Display Component of a specific type of an entity object
         * 
         * @param entity 
         * @param type
         * @return std::shared_ptr<IComponent>
         */
        std::shared_ptr<IComponent> getDisplayComponentOfSpecifiedType(const std::shared_ptr<entities::Entity> &entity, const std::type_index &type) override;

        /**
         * @brief Get the IO Components from an entity by his id
         * 
         * @param idEntity 
         * @return std::list<std::shared_ptr<IComponent>> 
         */
        std::list<std::shared_ptr<IComponent>> getIOComponents(size_t idEntity) override;

        /**
         * @brief Get a IO Component of a specific type of an entityId
         * 
         * @param idEntity 
         * @param type
         * @return std::shared_ptr<IComponent>
         */
        std::shared_ptr<IComponent> getIOComponentOfSpecifiedType(size_t idEntity, const std::type_index &type) override;
    
        /**
         * @brief Get The IO Components from an entity
         * 
         * @param entity 
         * @return std::list<std::shared_ptr<IComponent>> 
         */
        std::list<std::shared_ptr<IComponent>> getIOComponents(const std::shared_ptr<entities::Entity> &entity) override;

        /**
         * @brief Get an IO Component of a specific type of an entity object
         * 
         * @param entity 
         * @param type
         * @return std::shared_ptr<IComponent>
         */
        std::shared_ptr<IComponent> getIOComponentOfSpecifiedType(const std::shared_ptr<entities::Entity> &entity, const std::type_index &type) override;

        /**
         * @brief Get the Game Logic Components from an entity by his id
         * 
         * @param idEntity 
         * @return std::list<std::shared_ptr<IComponent>> 
         */
        std::list<std::shared_ptr<IComponent>> getGameLogicComponents(size_t idEntity) override;

        /**
         * @brief Get a GameLogic Component of a specific type of an entityId
         * 
         * @param idEntity 
         * @param type
         * @return std::shared_ptr<IComponent>
         */
        std::shared_ptr<IComponent> getGameLogicComponentOfSpecifiedType(size_t idEntity, const std::type_index &type) override;

        /**
         * @brief Get the Game Logic Component object
         * 
         * @param entity 
         * @return std::list<std::shared_ptr<IComponent>> 
         */
        std::list<std::shared_ptr<IComponent>> getGameLogicComponents(const std::shared_ptr<entities::Entity> &entity) override;

        /**
         * @brief Get a GameLogic Component of a specific type of an entity object
         * 
         * @param entity 
         * @param type
         * @return std::shared_ptr<IComponent>
         */
        std::shared_ptr<IComponent> getGameLogicComponentOfSpecifiedType(const std::shared_ptr<entities::Entity> &entity, const std::type_index &type) override;

        /**
         * @brief Add a Physic Component object
         * 
         * @param component 
         * @param idEntity 
         */
        void addPhysicComponent(std::shared_ptr<IComponent> component, size_t idEntity) override;

        /**
         * @brief Add a Physic Component object
         * 
         * @param component 
         * @param entity 
         */
        void addPhysicComponent(std::shared_ptr<IComponent> component, const std::shared_ptr<entities::Entity> &entity) override;

        /**
         * @brief Add a Display Component object
         * 
         * @param component 
         * @param idEntity 
         */
        void addDisplayComponent(std::shared_ptr<IComponent> component, size_t idEntity) override;

        /**
         * @brief Add a Display Component object
         * 
         * @param component 
         * @param entity 
         */
        void addDisplayComponent(std::shared_ptr<IComponent> component, const std::shared_ptr<entities::Entity> &entity) override;

        /**
         * @brief Add a IO Component object
         * 
         * @param component 
         * @param idEntity 
         */
        void addIOComponent(std::shared_ptr<IComponent> component, size_t idEntity) override;

        /**
         * @brief Add a IO component object
         * 
         * @param component 
         * @param entity 
         */
        void addIOComponent(std::shared_ptr<IComponent> component, const std::shared_ptr<entities::Entity> &entity) override;

        /**
         * @brief Add a GameLogic Component object
         * 
         * @param component 
         * @param idEntity 
         */
        void addGameLogicComponent(std::shared_ptr<IComponent> component, size_t idEntity) override;

        /**
         * @brief Add a Game Logic Component object
         * 
         * @param component 
         * @param entity 
         */
        void addGameLogicComponent(std::shared_ptr<IComponent> component, const std::shared_ptr<entities::Entity> &entity) override;

        /**
         * @brief Remove all the ecs::components from an entity
         * 
         * @param idEntity 
         */
        void deleteComponents(size_t idEntity) override;

        /**
         * @brief Delete all the ecs::components from an entity
         * 
         * @param entity 
         */
        void deleteComponents(const std::shared_ptr<entities::Entity> &entity) override;

        /**
         * @brief Delete all the components
         * 
         */
        void deleteAllComponents() override;
    };
}

#endif //COMPONENTMANAGER_HPP_