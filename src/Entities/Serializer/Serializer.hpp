/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Serializer.hpp
*/

#ifndef SERIALIZER_HPP__
#define SERIALIZER_HPP__

#include "Position.hpp"
#include "Rotation.hpp"
#include "EntityManager.hpp"
#include "PacketManager.hpp"

namespace ecs::entities
{

class Serializer
{
private:
    const std::shared_ptr<IEntityManager> &_entityManager;
    const std::shared_ptr<ecs::components::IComponentManager> &_componentManager;

    /**
     * @brief Add the serialazable components inside the entityPacket
     * 
     * @param toFill 
     * @param entity 
     * @param componentsManager 
     */
    void addPhysicsComponent(ecs::network::Entity &toFill, const std::shared_ptr<Entity> &entity);
    void addGraphicalComponent(ecs::network::Entity &toFill, const std::shared_ptr<Entity> &entity);

public:
    Serializer(const std::shared_ptr<IEntityManager> &entityManager, const std::shared_ptr<ecs::components::IComponentManager> &componentManager);
    ~Serializer();

    /**
     * @brief Returns the display data serialized for the packet
     * 
     * @param entityManager 
     * @param componentManager 
     * @return std::list<ecs::network::Entity> 
     */
    std::list<ecs::network::Entity> serialize();
};
} // namespace ecs::entities

#endif //SERIALIZER_HPP__