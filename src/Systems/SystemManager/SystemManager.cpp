/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** SystemManager.cpp
*/

#include <iostream>
#include "SystemResponse.hpp"
#include "SystemExceptions.hpp"
#include "SystemManager.hpp"

namespace ecs::system
{
    SystemManager::SystemManager(std::shared_ptr<ManagerWrapper> managerWrapper) :
    _managerWrapper(managerWrapper),
    _entityFactory(nullptr)
    {
    }
    
    SystemManager::~SystemManager()
    {
    }

    std::list<int> &SystemManager::getEntitiesToDelete()
    {
        return _entitiesToDelete;
    }

    void SystemManager::checkIfEntityFactory()
    {
        if (_entityFactory == nullptr)
            throw SystemExceptions("No entity factory given, make sur to add it", "SystemManager");
    }

    SystemResponse SystemManager::updateAll()
    {
        checkIfEntityFactory();
        SystemResponse current;
        for (auto &it : _systems) {
            current = it->update();
            if (current.getAction() != ecs::system::SystemResponse::NOACTION) {
                std::cout << "Test" << std::endl;
                break;
            }
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

    void SystemManager::setEntityFactory(std::shared_ptr<ecs::entities::IEntityFactory> entityFactory)
    {
        _entityFactory = entityFactory;
    }
}