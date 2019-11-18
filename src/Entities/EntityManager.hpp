/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** EntityFactory.hpp
*/

#ifndef ENTITYMANAGER_HPP__
#define ENTITYMANAGER_HPP__

#include <vector>
#include "IEntityManager.hpp"

namespace entities
{
    class EntityManager  : public IEntityManager
    {
    private:
        std::vector<std::shared_ptr<Entity>> _entities;

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

    public:
        EntityManager();
        ~EntityManager();

        const std::vector<std::shared_ptr<Entity>> &getAllEntities() const override;
        const std::shared_ptr<Entity> &getEntityById(size_t idEntity) const override;
        void addEntity(std::shared_ptr<Entity> entity) override;
        void deleteEntity(size_t idEntity) override;
        void deleteEntity(const std::shared_ptr<Entity>& entity) override;
        void deleteAll() override;
    };
}

#endif //ENTITYMANAGER_HPP__