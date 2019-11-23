/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** EntityFactory.hpp
*/

#ifndef ENTITYFACTORY_HPP__
#define ENTITYFACTORY_HPP__

#include <map>
#include "IEntityConstructor.hpp"
#include "IEntityFactory.hpp"
#include "IEntityManager.hpp"
#include "IComponentManager.hpp"

namespace ecs::entities
{
    class EntityFactory : public IEntityFactory
    {
    private:
        std::shared_ptr<IEntityManager> _entityManager;
        std::shared_ptr<components::IComponentManager> _componentManager;
        std::map<std::string, std::shared_ptr<IEntityConstructor>> _creationFunction;

    private:
        /**
         * @brief Check if an Entity Constructor exist
         * 
         * @param name 
         * @return true 
         * @return false 
         */
        bool isExisting(const std::string &name);

    public:
        /**
         * @brief Construct a new Entity Factory object
         * 
         * @param manager : Entity manager
         */
        EntityFactory(std::shared_ptr<IEntityManager> entityManager, std::shared_ptr<components::IComponentManager> componentsManager);
        ~EntityFactory();

        /**
         * @brief Create a Entity object by his name
         * 
         * @param name 
         * @return std::shared_ptr<Entity> 
         */
        std::shared_ptr<Entity> createEntity(const std::string &name) override;

        /**
         * @brief Add an entity constructor that will be used in the entity factory
         * 
         * @param constructor 
         */
        void addEntityConstructor(std::shared_ptr<IEntityConstructor> constructor) override;
    };
}

#endif //ENTITYFACTORY_HPP__