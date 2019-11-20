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
        bool isExisting(const std::string &name);

    public:
        /**
         * @brief Construct a new Entity Factory object
         * 
         * @param manager : Entity manager
         */
        EntityFactory(std::shared_ptr<IEntityManager> entityManager, std::shared_ptr<components::IComponentManager> componentsManager);
        ~EntityFactory();
        std::shared_ptr<Entity> createEntity(const std::string &name) override;
        void addEntityConstructor(std::shared_ptr<IEntityConstructor> constructor) override;
    };
}

#endif //ENTITYFACTORY_HPP__