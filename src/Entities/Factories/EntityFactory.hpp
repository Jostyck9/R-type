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

        /**
         * @brief Update the entity if aready existing (userfull between server and client)
         * 
         * @param entity 
         * @return std::shared_ptr<ecs::entities::Entity> 
         */
        std::shared_ptr<ecs::entities::Entity> updateIfExisting(const ecs::network::PacketManager::Entity &entity);
        
        using ptrFunc = void (ecs::entities::EntityFactory::*)(std::shared_ptr<ecs::entities::Entity>&, const ecs::network::PacketManager::Component);
        std::map<ecs::network::ComponentType, ptrFunc> _functionsUpdate;

        /**
         * @brief add a Position to an Entity
         * 
         * @param entity 
         * @param data 
         */
        void addPosition(std::shared_ptr<ecs::entities::Entity> &entity, const ecs::network::PacketManager::Component data);
        /**
         * @brief add a Rotation to an Entity
         * 
         * @param entity 
         * @param data 
         */
        void addRotation(std::shared_ptr<ecs::entities::Entity> &entity, const ecs::network::PacketManager::Component data);

    public:
        /**
         * @brief Construct a new Entity Factory object
         * 
         * @param manager : Entity manager
         */
        EntityFactory(std::shared_ptr<IEntityManager> entityManager, std::shared_ptr<components::IComponentManager> componentsManager);
        ~EntityFactory();

        /**
         * @brief Create a Entity object
         * 
         * @param name 
         * @param pos : std::pair<float, float> = (0, 0)
         * @param velocity : std::pair<float, float> = (0, 0)
         * @param rotation 
         * @return std::shared_ptr<Entity> 
         */
        std::shared_ptr<Entity> createEntity(const std::string &name, std::pair<float, float> pos = std::make_pair(0, 0), std::pair<float, float> velocity = std::make_pair(0, 0), float rotation = 0) override;

        /**
         * @brief Add an entity constructor that will be used in the entity factory
         * 
         * @param constructor 
         */
        void addEntityConstructor(std::shared_ptr<IEntityConstructor> constructor) override;

        /**
        * @brief Create an Entity object from an EntityPacket or update it if existing
        * 
        * @param entity 
        * @return std::shared_ptr<Entity> 
        */
        std::shared_ptr<Entity> createEntity(ecs::network::PacketManager::Entity &entity) override;

        /**
         * @brief Delete all entities constructor
         * 
         */
        void deleteAll() override;
    
        /**
         * @brief Remove an entity constructor
         * 
         * @param name 
         * @return true 
         * @return false if not existing
         */
        bool remove(const std::string &name) override;
    };
}

#endif //ENTITYFACTORY_HPP__