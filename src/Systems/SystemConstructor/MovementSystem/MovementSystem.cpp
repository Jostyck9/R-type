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
#include "Sprite.hpp"
#include "EnemiesController.hpp"

using namespace ecs::system;
using namespace ecs::components;

MovementSystem::MovementSystem(std::shared_ptr<ecs::IManagerWrapper> &managerWrapper, std::shared_ptr<ecs::entities::IEntityFactory> &entityFactory, std::list<int> &entitiesToDelete) : ASystem(managerWrapper, entityFactory, entitiesToDelete)
{
    _myTimer.start();
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
    int directionY = 1;

    if (speed->getVelocityX() < 0)
    {
        directionX = -1;
        if (speed->getVelocityY() != 0)
            directionY = -1;
    }
    newPos.first = newPos.first + (speed->getVelocityX()) * _myTimer.getElapsedSeconds();
    newPos.second = newPos.second + (speed->getVelocityY()) * _myTimer.getElapsedSeconds();

    float radius = std::sqrt(std::pow(newPos.first - srcPos.first, 2) + std::pow(newPos.second - srcPos.second, 2));
    float angle = rot->getRadAngle() + std::atan((newPos.second - srcPos.second) / (newPos.first - srcPos.first));

    newPos.first = (directionX * radius * std::cos(angle)) + srcPos.first;
    newPos.second = (directionY * radius * std::sin(angle)) + srcPos.second;

    return newPos;
}

bool MovementSystem::isColliding(const data &box1, const data &box2) const
{
    if (box1.box == nullptr || box2.box == nullptr)
        throw SystemExceptions("No box collision to check", "MovementSystem::isColliding");
    // float width = ((box1.nextPos.first + box1.box->getX()) - (box1.pos->getX() + box1.box->getX())) + box1.box->getWidth();
    // float height = ((box1.nextPos.second + box1.box->getY()) - (box1.pos->getY() + box1.box->getY())) + box1.box->getHeight();
    float width = box1.box->getWidth();
    float height = box1.box->getHeight();

    if (
        // box1.pos->getX() + box1.box->getX() + width > box2.pos->getX() + box2.box->getX() &&
        // box2.pos->getX() + box2.box->getX() + box2.box->getWidth() > box1.pos->getX() + box1.box->getX() &&
        // box1.pos->getY() + box1.box->getY() + height > box2.pos->getY() + box2.box->getY() &&
        // box2.pos->getY() + box2.box->getY() + box2.box->getHeight() > box1.pos->getY() + box1.box->getY()
        box1.nextPos.first + box1.box->getX() + width > box2.pos->getX() + box2.box->getX() &&
        box2.pos->getX() + box2.box->getX() + box2.box->getWidth() > box1.nextPos.first + box1.box->getX() &&
        box1.nextPos.second + box1.box->getY() + height > box2.pos->getY() + box2.box->getY() &&
        box2.pos->getY() + box2.box->getY() + box2.box->getHeight() > box1.nextPos.second + box1.box->getY())
    {
        return true;
    }
    return false;
}

void MovementSystem::updateAll(std::vector<data> &all)
{
    bool collide = false;

    for (auto &it : all)
    {
        if (it.box != nullptr)
        {
            it.box->setCollinding(false);
            it.box->clearTags();
        }
    }
    for (size_t i = 0; i < all.size(); i++)
    {
        all[i].nextPos = getNextPos(all[i].pos, all[i].rot, all[i].speed);
        for (size_t y = i + 1; y < all.size(); y++)
        {
            try
            {
                if (all[i].box != nullptr && all[y].box != nullptr && isColliding(all[i], all[y]))
                {
                    all[i].box->addTag(all[y].entity->getID(), all[y].box->getTag());
                    all[y].box->addTag(all[i].entity->getID(), all[i].box->getTag());
                    if (!all[i].box->isTriggered() && !all[y].box->isTriggered())
                        collide = true;
                    all[i].box->setCollinding(true);
                    all[y].box->setCollinding(true);
                    break;
                }
            }
            catch (SystemExceptions &e)
            {
            }
        }
        if (all[i].box != nullptr)
        {
			if (all[i].box->isTriggered()) {
				collide = false;
			}
            else if (all[i].box->getCollidedTags().size() != 0)
            {
                collide = true;
            }
        }
        if (all[i].box == nullptr || !collide)
        {
            all[i].pos->setPosition(all[i].nextPos);
        }
        collide = false;
    }
    _myTimer.restart();
}

void MovementSystem::deleteIfOutOfWindow(void)
{
    auto entities = _managerWrapper->getEntityManager()->getAllEntities();
    std::shared_ptr<ecs::components::Sprite> sprite;
    std::shared_ptr<ecs::components::Position> pos;
    std::shared_ptr<ecs::components::EnemiesController> ennemyCtrl;
    for (size_t i = 0; i < entities.size(); i++)
    {
        try
        {
            sprite = std::dynamic_pointer_cast<ecs::components::Sprite>(_managerWrapper->getComponentManager()->getDisplayComponentOfSpecifiedType(entities[i]->getID(), std::type_index(typeid(ecs::components::Sprite))));
            pos = std::dynamic_pointer_cast<ecs::components::Position>(_managerWrapper->getComponentManager()->getPhysicComponentOfSpecifiedType(entities[i]->getID(), std::type_index(typeid(ecs::components::Position))));
        }
        catch (ComponentExceptions &e)
        {
            continue;
        }
        try
        {
            ennemyCtrl = std::dynamic_pointer_cast<ecs::components::EnemiesController>(_managerWrapper->getComponentManager()->getGameLogicComponentOfSpecifiedType(entities[i]->getID(), std::type_index(typeid(ecs::components::EnemiesController))));
            if ((pos->getX() < (0 - sprite->getRect().getWidth())) || (pos->getX() > (1700)))
            {
                _entitiesToDelete.push_front(entities[i]->getID());
            }
            continue;
        }
        catch (ComponentExceptions &e)
        {
        }
        if ((pos->getX() < (0 - sprite->getRect().getWidth())) || (pos->getX() > (1510)))
        {
            _entitiesToDelete.push_front(entities[i]->getID());
        }
    }
}

SystemResponse MovementSystem::update()
{
    std::vector<data> allData;

    deleteIfOutOfWindow();
    for (auto &it : _managerWrapper->getEntityManager()->getAllEntities())
    {
        data current;
        try
        {
            current.pos = std::reinterpret_pointer_cast<Position>(_managerWrapper->getComponentManager()->getPhysicComponentOfSpecifiedType(it, std::type_index(typeid(ecs::components::Position))));
            current.rot = std::reinterpret_pointer_cast<Rotation>(_managerWrapper->getComponentManager()->getPhysicComponentOfSpecifiedType(it, std::type_index(typeid(ecs::components::Rotation))));
            current.speed = std::reinterpret_pointer_cast<Velocity>(_managerWrapper->getComponentManager()->getPhysicComponentOfSpecifiedType(it, std::type_index(typeid(ecs::components::Velocity))));
            current.entity = it;
        }
        catch (ComponentExceptions &e)
        {
            std::cerr << e.what() << " : at " << e.where() << std::endl;
            continue;
        }
        try
        {
            current.box = std::reinterpret_pointer_cast<Collision>(_managerWrapper->getComponentManager()->getPhysicComponentOfSpecifiedType(it, std::type_index(typeid(ecs::components::Collision))));
        }
        catch (ComponentExceptions &e)
        {
            current.box = nullptr;
        }
        allData.push_back(current);
    }
    updateAll(allData);
    return SystemResponse();
}