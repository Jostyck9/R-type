/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** main_client.cpp
*/

#include "EntityManager.hpp"
#include "ComponentManager.hpp"
#include "SystemManager.hpp"

int main()
{
    std::shared_ptr<entities::IEntityManager> entityManager = std::make_shared<entities::EntityManager>();
    std::shared_ptr<components::IComponentManager> componentManager = std::make_shared<components::ComponentManager>();
    std::shared_ptr<ecs::system::ISystemManager> systemManager = std::make_shared<ecs::system::SystemManager>(entityManager, componentManager);

    std::shared_ptr<entities::Entity> entity = std::make_shared<entities::Entity>();
    
    return 0;
}