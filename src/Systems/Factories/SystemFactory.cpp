/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** SystemFactory.cpp
*/

#include "SystemFactory.hpp"
#include "SystemExceptions.hpp"

using namespace ecs::system;

SystemFactory::SystemFactory(std::shared_ptr<ecs::ManagerWrapper> &_managerWrapper,
                             std::shared_ptr<ecs::entities::IEntityFactory> &entityFactory,
                             std::shared_ptr<ISystemManager> systemManager) : _managerWrapper(_managerWrapper),
                                                                              _systemManager(systemManager),
                                                                              _entityFactory(entityFactory)
{
}

SystemFactory::~SystemFactory()
{
}

bool SystemFactory::isExisting(const std::string &name)
{
    if (this->_createFunction.find(name) == _createFunction.end())
        return (false);
    return (true);
}

void SystemFactory::addSystemConstructor(std::shared_ptr<ISystemConstructor> constructor)
{
    auto name = constructor->create(_managerWrapper, _systemManager->getEntitiesToDelete())->getName();
    if (isExisting(name))
    {
        throw SystemExceptions("Error: Could not add system Constructor ", std::string(__FILE__) + ' ' + std::to_string(__LINE__));
    }
    _createFunction[name] = constructor;
}

std::shared_ptr<ISystem> SystemFactory::createSystem(const std::string &name)
{
    if (!isExisting(name))
    {
        throw SystemExceptions("Error: Could not create system \'" + name + '\'', std::string(__FILE__) + ' ' + std::to_string(__LINE__));
    }
    return (_createFunction[name])->create(_managerWrapper, _entityFactory, _systemManager->getEntitiesToDelete());
}

bool SystemFactory::remove(const std::string &name)
{
    if (!isExisting(name))
        return false;
    _createFunction.erase(name);
    return true;
}

void SystemFactory::deleteAll()
{
    _createFunction.clear();
}