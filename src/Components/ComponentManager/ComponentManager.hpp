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

namespace components
{
    /**
     * @brief Manage all the components of the game
     * 
     */
    class ComponentManager : public IComponentManager
    {
    private:
        std::multimap<size_t, std::shared_ptr<IComponent>> _physic;
        std::multimap<size_t, std::shared_ptr<IComponent>> _display;
        std::multimap<size_t, std::shared_ptr<IComponent>> _io;
        std::multimap<size_t, std::shared_ptr<IComponent>> _network;
        std::multimap<size_t, std::shared_ptr<IComponent>> _gameLogic;

        typedef std::multimap<size_t, std::shared_ptr<IComponent>>::iterator MMAPIterator;

        /**
         * @brief Extract the components from the map given with the idEntity
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
        std::list<std::reference_wrapper<std::shared_ptr<IComponent>>> getPhysicComponent(size_t idEntity) override;
        /**
         * @brief Get the Display Components from an entity by his id
         * 
         * @param idEntity 
         * @return std::list<std::reference_wrapper<std::shared_ptr<IComponent>>> 
         */
        std::list<std::reference_wrapper<std::shared_ptr<IComponent>>> getDisplayComponent(size_t idEntity) override;

        /**
         * @brief Get the IO Components from an entity by his id
         * 
         * @param idEntity 
         * @return std::list<std::reference_wrapper<std::shared_ptr<IComponent>>> 
         */
        std::list<std::reference_wrapper<std::shared_ptr<IComponent>>> getIOComponent(size_t idEntity) override;

        /**
         * @brief Get the Network Components from an entity by his id
         * 
         * @param idEntity 
         * @return std::list<std::reference_wrapper<std::shared_ptr<IComponent>>> 
         */
        std::list<std::reference_wrapper<std::shared_ptr<IComponent>>> getNetworkComponent(size_t idEntity) override;

        /**
         * @brief Get the Game Logic Components from an entity by his id
         * 
         * @param idEntity 
         * @return std::list<std::reference_wrapper<std::shared_ptr<IComponent>>> 
         */
        std::list<std::reference_wrapper<std::shared_ptr<IComponent>>> getGameLogicComponent(size_t idEntity) override;

        /**
         * @brief Add a Physic Component object
         * 
         * @param component 
         * @param idEntity 
         */
        void addPhysicComponent(std::shared_ptr<IComponent> component, size_t idEntity) override;

        /**
         * @brief Add a Display Component object
         * 
         * @param component 
         * @param idEntity 
         */
        void addDisplayComponent(std::shared_ptr<IComponent> component, size_t idEntity) override;

        /**
         * @brief Add a IO Component object
         * 
         * @param component 
         * @param idEntity 
         */
        void addIOComponent(std::shared_ptr<IComponent> component, size_t idEntity) override;

        /**
         * @brief Add a Network Component object
         * 
         * @param component 
         * @param idEntity 
         */
        void addNetworkComponent(std::shared_ptr<IComponent> component, size_t idEntity) override;

        /**
         * @brief Add a GameLogic Component object
         * 
         * @param component 
         * @param idEntity 
         */
        void addGameLogicComponent(std::shared_ptr<IComponent> component, size_t idEntity) override;

        /**
         * @brief Remove all the components from an entity
         * 
         * @param idEntity 
         */
        void removeComponent(size_t idEntity) override;
    };
}

#endif //COMPONENTMANAGER_HPP_