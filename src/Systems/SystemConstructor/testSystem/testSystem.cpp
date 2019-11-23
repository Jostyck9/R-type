/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** testSystem.cpp
*/

#include "DisplaySystem.hpp"
#include "testSystem.hpp"

using namespace ecs::system;

testSystem::testSystem()
{
}

testSystem::~testSystem()
{
}

std::shared_ptr<ecs::system::ISystem> testSystem::create(
    std::shared_ptr<ecs::entities::IEntityManager> &entityManager,
    std::shared_ptr<ecs::components::IComponentManager> &componentsManager,
    std::list<int> &entitiesToDelete)
{
    return std::make_shared<ecs::system::DisplaySystem>(entityManager, componentsManager, entitiesToDelete);
}

std::string testSystem::getName()
{
    return std::string("Display");
}