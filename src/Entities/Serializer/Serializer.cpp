/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Serializer.cpp
*/

#include "Serializer.hpp"

namespace ecs::entities
{

Serializer::Serializer(
    const std::shared_ptr<IEntityManager> &entityManager,
    const std::shared_ptr<ecs::components::IComponentManager> &componentManager) : _entityManager(entityManager),
                                                                                   _componentManager(componentManager)
{
}

Serializer::~Serializer()
{
}

std::list<ecs::network::PacketManager::Entity> Serializer::serialize()
{
    std::list<ecs::network::PacketManager::Entity> toReturn;

    for (auto &it : _entityManager->getAllEntities())
    {
        ecs::network::PacketManager::Entity toFill;

        if (it->getInGameID() == it->NOGAMEID)
            continue;
        toFill.nbrComponents = 0;
        toFill.id = it->getInGameID();
        addPhysicsComponent(toFill, it);
        addGraphicalComponent(toFill, it);
        toReturn.push_back(toFill);
        if (toFill.nbrComponents == ecs::network::PacketManager::MAX_COMPONENTS)
            break;
    }
    return toReturn;
}

void Serializer::addPhysicsComponent(ecs::network::PacketManager::Entity &toFill, const std::shared_ptr<Entity> &entity)
{
    bool position = false;
    bool rotation = false;

    for (auto &it : _componentManager->getPhysicComponents(entity)) {
        if ((position && rotation) || toFill.nbrComponents == ecs::network::PacketManager::MAX_COMPONENTS)
            return;

        ecs::network::PacketManager::Component compoToFill;
        if (it->getType() == std::type_index(typeid(ecs::components::Position))) {
            auto pos = std::reinterpret_pointer_cast<ecs::components::Position>(it);
            compoToFill.type = ecs::network::POSITION;
            compoToFill._position.x = pos->getX();
            compoToFill._position.y = pos->getY();
            toFill.components[static_cast<int>(toFill.nbrComponents)] = compoToFill;
            toFill.nbrComponents++;
            position = true;
            continue;
        }

        if (it->getType() == std::type_index(typeid(ecs::components::Rotation))) {
            auto rot = std::reinterpret_pointer_cast<ecs::components::Rotation>(it);
            compoToFill.type = ecs::network::ROTATION;
            compoToFill._rotation.radAngle = rot->getRadAngle();
            toFill.components[static_cast<int>(toFill.nbrComponents)] = compoToFill;
            toFill.nbrComponents++;
            rotation = true;
            continue;
        }
    }
}

void Serializer::addGraphicalComponent(ecs::network::PacketManager::Entity &toFill, const std::shared_ptr<Entity> &entity)
{
    (void)toFill;
    (void)entity;
}

} // namespace ecs::entities