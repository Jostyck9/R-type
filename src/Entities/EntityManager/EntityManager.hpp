/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** EntityFactory.hpp
*/

#ifndef ENTITYMANAGER_HPP__
#define ENTITYMANAGER_HPP__

#include <map>
#include <vector>
#include "PacketManager.hpp"
#include "IComponentManager.hpp"
#include "IEntityManager.hpp"

namespace ecs::entities
{
    class EntityManager  : public IEntityManager
    {
    private:
        std::vector<std::shared_ptr<Entity>> _entities;
        std::shared_ptr<components::IComponentManager> _componentManager;

        /**
         * @brief Check if an entity is contained inside the manager
         * 
         * @param entity 
         * @return true 
         * @return false 
         */
        bool contains(const std::shared_ptr<Entity> &entity) const;

        /**
         * @brief Check if an entity is contained inside the manager
         * 
         * @param entity 
         * @return true 
         * @return false 
         */
        bool contains(const Entity &entity) const;

        /**
         * @brief Get the Entity By Game Id object, throw an entityException if not found
         * 
         * @param id 
         * @return std::shared_ptr<Entity>& 
         */
        std::shared_ptr<Entity> &getEntityByGameId(size_t id);

    private:
        using ptrFunc = void (EntityManager::*)(const std::shared_ptr<entities::Entity> &entity, const ecs::network::PacketManager::Component toAdd);
        std::map<ecs::network::ComponentType, ptrFunc> _functionsUpdate;

        /**
         * @brief update the position of an Entity
         * 
         * @param entity 
         * @param toAdd 
         */
        void updatePosition(const std::shared_ptr<entities::Entity> &entity, const ecs::network::PacketManager::Component toAdd);
        /**
         * @brief update the rotation
         *  of an Entity
         * 
         * @param entity 
         * @param toAdd 
         */
        void updateRotation(const std::shared_ptr<entities::Entity> &entity, const ecs::network::PacketManager::Component toAdd);

    public:
        /**
         * @brief Construct a new Entity Manager object
         * 
         * @param componentManager 
         */
        EntityManager(std::shared_ptr<components::IComponentManager> componentManager);
        ~EntityManager();

        /**
         * @brief Update an entity if existing (useful for network part)
         * 
         * @param toUpdate 
         * @return std::shared_ptr<Entity> 
         */
        std::shared_ptr<Entity> updateEntity(const ecs::network::PacketManager::Entity &toUpdate) override;

        /**
         * @brief Get All the Entities object
         * 
         * @return const std::vector<std::shared_ptr<Entity>>& 
         */
        const std::vector<std::shared_ptr<Entity>> &getAllEntities() const override;

        /**
         * @brief Get the Entity By Id object
         * 
         * @param idEntity 
         * @return const std::shared_ptr<Entity>& 
         */
        const std::shared_ptr<Entity> &getEntityById(size_t idEntity) const override;

        /**
         * @brief Add an entity in the entity Manager
         * 
         * @param entity 
         */
        void addEntity(std::shared_ptr<Entity> entity) override;

        /**
         * @brief Delete an entity and his associated components by his id
         * 
         * @param idEntity 
         */
        void deleteEntity(size_t idEntity) override;

        /**
         * @brief Delete an entity and his associated components from his reference 
         * 
         * @param entity 
         */
        void deleteEntity(const std::shared_ptr<Entity>& entity) override;

        /**
         * @brief Delete all the entities and their associated components
         * 
         */
        void deleteAll() override;
    };
}

#endif //ENTITYMANAGER_HPP__