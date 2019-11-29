/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** IFactory.hpp
*/

#ifndef IENTITYFACTORY_HPP__
#define IENTITYFACTORY_HPP__

#include <string>
#include <memory>
#include "PacketManager.hpp"
#include "IEntityConstructor.hpp"
#include "Entity.hpp"

namespace ecs::entities
{
class IEntityFactory
{
public:
    /**
     * @brief Create an Entity object with the specific name
     * 
     * @param name 
     * @return std::shared_ptr<Entity> 
     */
    virtual std::shared_ptr<Entity> createEntity(const std::string &name) = 0;

    /**
     * @brief Add an entityConstructor to use inside the factory
     * 
     * @param constructor 
     */
    virtual void addEntityConstructor(std::shared_ptr<IEntityConstructor> constructor) = 0;

    /**
     * @brief Create an Entity object from an EntityPacket or update it if existing
     * 
     * @param entity 
     * @return std::shared_ptr<Entity> 
     */
    virtual std::shared_ptr<Entity> createEntity(ecs::network::PacketManager::Entity &entity) = 0;

    /**
     * @brief Delete all entities constructor
     * 
     */
    virtual void deleteAll() = 0;
    
    /**
     * @brief Remove an entity constructor
     * 
     * @param name 
     * @return true 
     * @return false if not existing
     */
    virtual bool remove(const std::string &name) = 0;
};
} // namespace ecs::entities

#endif //IENTITYFACTORY_HPP__