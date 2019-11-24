/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** SystemFactory.cpp
*/

#include "SystemFactory.hpp"
#include "SystemExceptions.hpp"

using namespace ecs::system;

SystemFactory::SystemFactory(std::shared_ptr<ecs::entities::IEntityManager> entityManager, std::shared_ptr<ISystemManager> systemManager, std::shared_ptr<ecs::components::IComponentManager> componentsManager)
{
    this->_entityManager = entityManager;
    this->_systemManager = systemManager;
    this->_componentManager = componentsManager;
}

SystemFactory::~SystemFactory()
{
}

bool SystemFactory::isExisting(const std::string &name)
{
    if(this->_createFunction.find(name) == _createFunction.end())
        return (false);
    return (true);
}

void SystemFactory::addSystemConstructor(std::shared_ptr<ISystemConstructor> constructor)
{
    if (isExisting(constructor->getName())) {
        throw SystemExceptions("Error: Could not add system Constructor ", std::string(__FILE__) + ' ' + std::to_string(__LINE__));
    }
    _createFunction[constructor->getName()] = constructor;
}

std::shared_ptr<ISystem> SystemFactory::createSystem(const std::string &name)
{
    if (!isExisting(name)) {
        throw SystemExceptions("Error: Could not create system \'" + name + '\'', std::string(__FILE__) + ' ' + std::to_string(__LINE__));        
    }
    return (_createFunction[name])->create(this->_entityManager,this->_componentManager, this->_systemManager->getEntitiesToDelete());
}