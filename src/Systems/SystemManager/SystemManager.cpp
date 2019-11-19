/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** SystemManager.cpp
*/

#include "SystemManager.hpp"

namespace ecs::system
{
        
    SystemManager::SystemManager(std::shared_ptr<entities::IEntityManager> &entityManager, std::shared_ptr<ecs::components::IComponentManager> &componentManager) :
    _entityManager(entityManager),
    _componentManager(componentManager)
    {
    }
    
    SystemManager::~SystemManager()
    {
    }

    std::list<int> &SystemManager::getEntitiesToDelete()
    {
        return _entitiesToDelete;
    }

    void SystemManager::updateAll()
    {
        for (auto &it : _systems) {
            it->update();
        }
        for (auto &it : _entitiesToDelete) {
            _componentManager->removeComponents(it);
            _entityManager->deleteEntity(it);
        }
        _entitiesToDelete.clear();
    }

    void SystemManager::addSystem(std::shared_ptr<ISystem> system)
    {
        _systems.push_back(system);
    }
}