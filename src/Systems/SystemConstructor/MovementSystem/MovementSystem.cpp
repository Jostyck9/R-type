/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** MovementSystem.cpp
*/

#include <memory>
#include <iostream>
#include <cmath>
#include "ComponentExceptions.hpp"
#include "MovementSystem.hpp"
#include "Position.hpp"
#include "Rotation.hpp"
#include "Velocity.hpp"

using namespace ecs::system;
using namespace ecs::components;

MovementSystem::MovementSystem(std::shared_ptr<ecs::entities::IEntityManager> &entityManager,
                               std::shared_ptr<ecs::components::IComponentManager> &componentManager,
                               std::list<int> &entitiesToDelete) : ASystem(entityManager, componentManager, entitiesToDelete)
{
}

MovementSystem::~MovementSystem()
{
}

void MovementSystem::updatePostion(std::shared_ptr<Position> pos, std::shared_ptr<Rotation> rot, std::shared_ptr<Velocity> speed)
{
    if (speed->getVelocityX() == 0 && speed->getVelocityY() == 0)
        return;
    std::pair<float, float> srcPos = pos->getPosition();
    std::pair<float, float> newPos = srcPos;

    newPos.first = newPos.first + (1 * speed->getVelocityX());
    newPos.second = newPos.second + (1 * speed->getVelocityY());

    float radius = std::sqrt(std::pow(newPos.first - srcPos.first, 2) + std::pow(newPos.second - srcPos.second, 2));

    float angle = rot->getRadAngle() + std::atan((newPos.second - srcPos.second) / (newPos.first - srcPos.first));


    newPos.first = radius * std::cos(angle) + srcPos.first;
    newPos.second = radius * std::sin(angle) + srcPos.second;

    pos->setX(newPos.first);
    pos->setY(newPos.second);
}

void MovementSystem::update()
{
    for (auto &it : _entityManager->getAllEntities())
    {
        try
        {
            auto position = _componentManager->getPhysicComponentOfSpecifiedType(it, std::type_index(typeid(ecs::components::Position)));
            auto rotation = _componentManager->getPhysicComponentOfSpecifiedType(it, std::type_index(typeid(ecs::components::Rotation)));
            auto velocity = _componentManager->getPhysicComponentOfSpecifiedType(it, std::type_index(typeid(ecs::components::Velocity)));
            updatePostion(
                std::reinterpret_pointer_cast<Position>(position), 
                std::reinterpret_pointer_cast<Rotation>(rotation), 
                std::reinterpret_pointer_cast<Velocity>(velocity));
        }
        catch (ComponentExceptions &e)
        {
            std::cerr << e.what() << " : at " << e.where() << std::endl;
        }
    }
}