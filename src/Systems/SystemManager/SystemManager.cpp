/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** SystemManager.cpp
*/

#include "SystemManager.hpp"

namespace ecs::system
{
    SystemManager::SystemManager(std::shared_ptr<ManagerWrapper> managerWrapper) :
    _managerWrapper(managerWrapper)
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
            _managerWrapper->getComponentManager()->deleteComponents(it);
            _managerWrapper->getEntityManager()->deleteEntity(it);
        }
        _entitiesToDelete.clear();
    }

    void SystemManager::addSystem(std::shared_ptr<ISystem> system)
    {
        _systems.push_back(system);
    }
}