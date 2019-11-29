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
     * @brief Create a Entity object
     * 
     * @param name 
     * @param pos : std::pair<float, float> = (0, 0)
     * @param velocity : std::pair<float, float> = (0, 0)
     * @param rotation 
     * @return std::shared_ptr<Entity> 
     */
    virtual std::shared_ptr<Entity> createEntity(const std::string &name, std::pair<float, float> pos = std::make_pair(0, 0), std::pair<float, float> velocity = std::make_pair(0, 0), float rotation = 0) = 0;

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
};
} // namespace ecs::entities

#endif //IENTITYFACTORY_HPP__