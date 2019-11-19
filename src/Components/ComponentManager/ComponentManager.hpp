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
         * @return std::list<std::reference_wrapper<std::shared_ptr<IComponent>>> 
         */
        std::list<std::reference_wrapper<std::shared_ptr<IComponent>>> extractComponentsFrom(std::multimap<size_t, std::shared_ptr<IComponent>> &map, size_t idEntity);

    public:
        ComponentManager();
        ~ComponentManager();

        /**
         * @brief Get the Physic Components from an entity by his id 
         * 
         * @param idEntity 
         * @return std::list<std::reference_wrapper<std::shared_ptr<IComponent>>> 
         */
        std::list<std::reference_wrapper<std::shared_ptr<IComponent>>> getPhysicComponents(size_t idEntity) override;

        /**
         * @brief Get the Physic Component object
         * 
         * @param entity
         * @return std::list<std::reference_wrapper<std::shared_ptr<IComponent>>> 
         */
        virtual std::list<std::reference_wrapper<std::shared_ptr<IComponent>>> getPhysicComponents(const std::shared_ptr<entities::Entity> &entity) override;

        /**
         * @brief Get the Display Components from an entity by his id
         * 
         * @param idEntity 
         * @return std::list<std::reference_wrapper<std::shared_ptr<IComponent>>> 
         */
        std::list<std::reference_wrapper<std::shared_ptr<IComponent>>> getDisplayComponents(size_t idEntity) override;

        /**
         * @brief Get the Display Component object
         * 
         * @param entity 
         * @return std::list<std::reference_wrapper<std::shared_ptr<IComponent>>> 
         */
        virtual std::list<std::reference_wrapper<std::shared_ptr<IComponent>>> getDisplayComponents(const std::shared_ptr<entities::Entity> &entity) override;

        /**
         * @brief Get the IO Components from an entity by his id
         * 
         * @param idEntity 
         * @return std::list<std::reference_wrapper<std::shared_ptr<IComponent>>> 
         */
        std::list<std::reference_wrapper<std::shared_ptr<IComponent>>> getIOComponents(size_t idEntity) override;

        /**
         * @brief Get The IO Components from an entity
         * 
         * @param entity 
         * @return std::list<std::reference_wrapper<std::shared_ptr<IComponent>>> 
         */
        std::list<std::reference_wrapper<std::shared_ptr<IComponent>>> getIOComponents(const std::shared_ptr<entities::Entity> &entity) override;

        /**
         * @brief Get the Game Logic Components from an entity by his id
         * 
         * @param idEntity 
         * @return std::list<std::reference_wrapper<std::shared_ptr<IComponent>>> 
         */
        std::list<std::reference_wrapper<std::shared_ptr<IComponent>>> getGameLogicComponents(size_t idEntity) override;

        /**
         * @brief Get the Game Logic Component object
         * 
         * @param entity 
         * @return std::list<std::reference_wrapper<std::shared_ptr<IComponent>>> 
         */
        std::list<std::reference_wrapper<std::shared_ptr<IComponent>>> getGameLogicComponents(const std::shared_ptr<entities::Entity> &entity) override;

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
        void removeComponents(size_t idEntity) override;
    };
}

#endif //COMPONENTMANAGER_HPP_