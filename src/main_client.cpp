/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** main_client.cpp
*/

#include "EntityManager.hpp"
#include "EntityFactory.hpp"
#include "ComponentManager.hpp"
#include "SystemManager.hpp"
#include "Display/DisplaySystem.hpp"
#include "MovementSystem.hpp"
#include "Physics/Position.hpp"
#include "Physics/Velocity.hpp"
#include "TestEntity.hpp"

using namespace ecs::components;
using namespace ecs::system;
using namespace ecs::entities;

int main()
{
    std::shared_ptr<IComponentManager> componentManager = std::make_shared<ComponentManager>();
    std::shared_ptr<IEntityManager> entityManager = std::make_shared<EntityManager>(componentManager);
    std::shared_ptr<SystemManager> systemManager = std::make_shared<SystemManager>(entityManager, componentManager);
    std::shared_ptr<IEntityFactory> factory = std::make_shared<EntityFactory>(entityManager, componentManager);

    factory->addEntityConstructor(std::make_shared<TestEntity>());
    factory->createEntity("Test");

    systemManager->addSystem(std::make_shared<MovementSystem>(entityManager, componentManager, systemManager->getEntitiesToDelete()));
    systemManager->addSystem(std::make_shared<DisplaySystem>(entityManager, componentManager, systemManager->getEntitiesToDelete()));
    for (int i = 0; i < 10; i++) {
        systemManager->updateAll();
    }
    return 0;
}
