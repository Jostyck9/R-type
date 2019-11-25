/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** MovementSystem.cpp
*/

#include <memory>
#include <iostream>
#include <cmath>
#include "SystemExceptions.hpp"
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

std::pair<float, float> MovementSystem::getNextPos(std::shared_ptr<Position> &pos, std::shared_ptr<Rotation> &rot, std::shared_ptr<Velocity> &speed)
{
    if (speed->getVelocityX() == 0 && speed->getVelocityY() == 0)
        return pos->getPosition();
    std::pair<float, float> srcPos = pos->getPosition();
    std::pair<float, float> newPos = srcPos;
    int directionX = 1;

    if (speed->getVelocityX() < 0)
        directionX = -1;
    newPos.first = newPos.first + (1 * speed->getVelocityX());
    newPos.second = newPos.second + (1 * speed->getVelocityY());

    float radius = std::sqrt(std::pow(newPos.first - srcPos.first, 2) + std::pow(newPos.second - srcPos.second, 2));
    float angle = rot->getRadAngle() + std::atan((newPos.second - srcPos.second) / (newPos.first - srcPos.first));

    newPos.first = (directionX * radius * std::cos(angle)) + srcPos.first;
    newPos.second = (radius * std::sin(angle)) + srcPos.second;

    return newPos;
}

bool MovementSystem::isColliding(const data &box1, const data &box2) const
{
    float width = ((box1.nextPos.first + box1.box->getX()) - (box1.pos->getX() + box1.box->getX())) + box1.box->getWidth();
    float height = ((box1.nextPos.second + box1.box->getY()) - (box1.pos->getY() + box1.box->getY())) + box1.box->getHeight();

    if (box1.box == nullptr || box2.box == nullptr)
        throw SystemExceptions("No box collision to check", "MovementSystem::isColliding");
    if (
        box1.pos->getX() + box1.box->getX() + width > box2.pos->getX() + box2.box->getX() &&
        box2.pos->getX() + box2.box->getX() + box2.box->getWidth() > box1.pos->getX() + box1.box->getX() &&
        box1.pos->getY() + box1.box->getY() + height > box2.pos->getY() + box2.box->getY() &&
        box2.pos->getY() + box2.box->getY() + box2.box->getHeight() > box1.pos->getY() + box1.box->getY()
    )
    {
        return true;
    }
    return false;
}

void MovementSystem::updateAll(std::vector<data> &all)
{
    bool collide = false;

    for (auto &it : all) {
        it.box->setCollinding(false);
        it.box->clearTags();
    }
    for (size_t i = 0; i < all.size(); i++)
    {
        all[i].nextPos = getNextPos(all[i].pos, all[i].rot, all[i].speed);
        for (size_t y = i + 1; y < all.size(); y++)
        {
            try {
                if (isColliding(all[i], all[y])) {
                    all[i].box->addTag(all[y].entity->getID(), all[y].box->getTag());
                    all[y].box->addTag(all[i].entity->getID(), all[i].box->getTag());
                    // std::cout << "Collision HERE between " << all[i].box->getTag() << " and " << all[y].box->getTag() << std::endl;
                    if (!all[i].box->isTriggered() && !all[y].box->isTriggered())
                        collide = true;
                    all[i].box->setCollinding(true);
                    all[y].box->setCollinding(true);
                    break;
                }
            } catch (SystemExceptions &e) {
            }
        }
        if (!collide) {
            all[i].pos->setPosition(all[i].nextPos);
            collide = false;
        }
    }
}

void MovementSystem::update()
{
    std::vector<data> allData;

    for (auto &it : _entityManager->getAllEntities())
    {
        data current;
        try
        {
            current.pos = std::reinterpret_pointer_cast<Position>(_componentManager->getPhysicComponentOfSpecifiedType(it, std::type_index(typeid(ecs::components::Position))));
            current.rot = std::reinterpret_pointer_cast<Rotation>(_componentManager->getPhysicComponentOfSpecifiedType(it, std::type_index(typeid(ecs::components::Rotation))));
            current.speed = std::reinterpret_pointer_cast<Velocity>(_componentManager->getPhysicComponentOfSpecifiedType(it, std::type_index(typeid(ecs::components::Velocity))));
            current.entity = it;
        }
        catch (ComponentExceptions &e)
        {
            std::cerr << e.what() << " : at " << e.where() << std::endl;
            continue;
        }
        try
        {
            current.box = std::reinterpret_pointer_cast<Collision>(_componentManager->getPhysicComponentOfSpecifiedType(it, std::type_index(typeid(ecs::components::Collision))));
        }
        catch (ComponentExceptions &e)
        {
            current.box = nullptr;
        }
        allData.push_back(current);
    }
    updateAll(allData);
}