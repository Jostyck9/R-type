/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** SystemManager.cpp
*/

#include "SystemResponse.hpp"
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

    SystemResponse SystemManager::updateAll()
    {
        SystemResponse current;

        for (auto &it : _systems) {
            current = it->update();
            if (current.getAction() != ecs::system::SystemResponse::NOACTION)
                break;
        }
        for (auto &it : _entitiesToDelete) {
            _managerWrapper->getComponentManager()->deleteComponents(it);
            _managerWrapper->getEntityManager()->deleteEntity(it);
        }
        _entitiesToDelete.clear();
        return current;
    }

    void SystemManager::addSystem(std::shared_ptr<ISystem> system)
    {
        _systems.push_back(system);
    }

    void SystemManager::deleteAll()
    {
        _systems.clear();
    }
}