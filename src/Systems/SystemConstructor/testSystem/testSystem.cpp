/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** testSystem.cpp
*/

#include "SystemConstructor.hpp"
#include "DisplaySystem.hpp"
#include "testSystem.hpp"

using namespace ecs::system;

testSystem::testSystem(std::shared_ptr<ecs::ManagerWrapper> &managerWrapper,
                       std::list<int> &entitiesToDelete)
{
}

testSystem::~testSystem()
{
}

std::shared_ptr<ecs::system::ISystem> testSystem::create(std::shared_ptr<ecs::ManagerWrapper> &managerWrapper,
                                                         std::list<int> &entitiesToDelete)
{
    return std::make_shared<ecs::system::DisplaySystem>(managerWrapper, entitiesToDelete);
}

extern "C"
{
    ecs::system::ISystemConstructor *entryPoint(std::shared_ptr<ecs::ManagerWrapper> &managerWrapper, std::list<int> &entitiesToDelete)
    {
        return (new ecs::system::SystemConstructor<testSystem>());
    }
}