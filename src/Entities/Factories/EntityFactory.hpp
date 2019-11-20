/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** EntityFactory.hpp
*/

#ifndef ENTITYFACTORY_HPP__
#define ENTITYFACTORY_HPP__

#include <map>
#include "IEntityFactory.hpp"
#include "IEntityManager.hpp"
#include "IComponentManager.hpp"

namespace ecs::entities
{
    class EntityFactory : public IEntityFactory
    {
    private:
        typedef std::shared_ptr<Entity>(ecs::entities::EntityFactory::*pfunc)();

        std::shared_ptr<IEntityManager> _entityManager;
        std::shared_ptr<components::IComponentManager> _componentManager;

        std::map<std::string, pfunc> _creationFunction;

    private:
        std::shared_ptr<Entity> testEntity();

    public:
        /**
         * @brief Construct a new Entity Factory object
         * 
         * @param manager : Entity manager
         */
        EntityFactory(std::shared_ptr<IEntityManager> entityManager, std::shared_ptr<components::IComponentManager> componentsManager);
        ~EntityFactory();
        std::shared_ptr<Entity> createEntity(const std::string &name) override;
    };
}

#endif //ENTITYFACTORY_HPP__