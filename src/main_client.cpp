/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** main_client.cpp
*/

#include "EntityManager.hpp"
#include "ComponentManager.hpp"
#include "SystemManager.hpp"
#include "Display/DisplaySystem.hpp"
#include "Display/PhysicsSystem.hpp"
#include "Physics/Position.hpp"
#include "Physics/Velocity.hpp"

int main()
{
    std::shared_ptr<entities::IEntityManager> entityManager = std::make_shared<entities::EntityManager>();
    std::shared_ptr<ecs::components::IComponentManager> componentManager = std::make_shared<ecs::components::ComponentManager>();
    std::shared_ptr<ecs::system::SystemManager> systemManager = std::make_shared<ecs::system::SystemManager>(entityManager, componentManager);

    std::shared_ptr<entities::Entity> entity = std::make_shared<entities::Entity>();
    entityManager->addEntity(entity);
    componentManager->addPhysicComponent(std::make_shared<ecs::components::Position>(), entity);
    componentManager->addPhysicComponent(std::make_shared<ecs::components::Velocity>(2), entity);
    systemManager->addSystem(std::make_shared<ecs::system::DisplaySystem>(entityManager, componentManager, systemManager->getEntitiesToDelete()));
    systemManager->addSystem(std::make_shared<ecs::system::PhysicsSystem>(entityManager, componentManager, systemManager->getEntitiesToDelete()));

    for (int i = 0; i < 10; i++) {
        systemManager->updateAll();
    }
    return 0;
}