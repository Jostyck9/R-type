/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** IEntityMANAGER.hpp
*/

#ifndef IENTITYMANAGER__HPP__
#define IENTITYMANAGER__HPP__

#include <memory>
#include <vector>
#include "Entity.hpp"
#include "PacketManager.hpp"

namespace ecs::entities
{
    class IEntityManager
    {
    public:
        /**
         * @brief Update an entity if existing (useful for network part)
         * 
         * @param toUpdate 
         * @return true if existing and updated
         * @return false if net existing
         */
        virtual std::shared_ptr<Entity> updateEntity(const ecs::network::PacketManager::Entity &toUpdate) = 0;

        /**
         * @brief Get the Entity By Id object
         * 
         * @param idEntity 
         * @return const std::shared_ptr<Entity>& 
         */
        virtual const std::shared_ptr<Entity> &getEntityById(size_t idEntity) const = 0;

        /**
         * @brief Get the All Entities object
         * 
         * @return const std::vector<std::shared_ptr<Entity>>& 
         */
        virtual const std::vector<std::shared_ptr<Entity>> &getAllEntities() const = 0;

        /**
         * @brief Add en entity in the manager
         * 
         * @param entity 
         */
        virtual void addEntity(std::shared_ptr<Entity> entity) = 0;

        /**
         * @brief Delete the correspondnat entity
         * 
         * @param idEntity 
         */
        virtual void deleteEntity(size_t idEntity) = 0;

        /**
         * @brief Delete the correspondnat entity
         * 
         * @param idEntity 
         */
        virtual void deleteEntity(const std::shared_ptr<Entity>& idEntity) = 0;

        /**
         * @brief Delete all the entities
         * 
         */
        virtual void deleteAll() = 0;
    };
}

#endif //IENTITYMANAGER__HPP__