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
    virtual std::shared_ptr<Entity> createEntity(ecs::network::Entity &entity) = 0;
};
} // namespace ecs::entities

#endif //IENTITYFACTORY_HPP__