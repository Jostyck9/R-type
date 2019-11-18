/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** EntityManager.cpp
*/

#include "EntityManager.hpp"

using namespace entities;

EntityManager::EntityManager()
{
}

EntityManager::~EntityManager()
{
}

bool EntityManager::contains(const std::shared_ptr<Entity> &entity) const
{
    for (auto &it : _entities) {
        if (*it == *entity)
            return true;
    }
    return false;
}

bool EntityManager::contains(const Entity &entity) const
{
    for (auto &it : _entities) {
        if (*it == entity)
            return true;
    }
    return false;
}

const std::shared_ptr<Entity> &EntityManager::getEntityById(size_t idEntity) const
{
    for (auto &it : _entities) {
        if (it->getID() == idEntity)
            return it;
    }
    // TODO Create all exceptions : Here the noEntity
    throw new std::exception();
}

const std::vector<std::shared_ptr<Entity>> &EntityManager::getAllEntities() const
{
    return (_entities);
}

void EntityManager::addEntity(std::shared_ptr<Entity> entity)
{
    if (contains(entity))
        return;
    _entities.push_back(entity);
}

void EntityManager::deleteEntity(size_t idEntity)
{
    for (auto it = _entities.begin(); it != _entities.end(); it++) {
        if ((*it)->getID() == idEntity) {
            _entities.erase(it);
            return;
        }
    }
}

void EntityManager::deleteEntity(const std::shared_ptr<Entity>& entity)
{
    for (auto it = _entities.begin(); it != _entities.end(); it++) {
        if (**it == *entity) {
            _entities.erase(it);
            return;
        }
    }
}

void EntityManager::deleteAll()
{
    _entities.clear();
}
