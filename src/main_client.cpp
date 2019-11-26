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
#include "Display/PhysicsSystem.hpp"
#include "Physics/Position.hpp"
#include "Physics/Velocity.hpp"
#include "TestEntity.hpp"
#include "IRenderManager.hpp"
#include "SFMLRenderManager.hpp"
#include "ManagerWrapper.hpp"

using namespace ecs::components;
using namespace ecs::system;
using namespace ecs::entities;

int main()
{
    bool isPlaying = false;
    std::shared_ptr<ecs::ManagerWrapper> managerWrapper = std::make_shared<ecs::ManagerWrapper>();
    std::shared_ptr<IEntityFactory> factory = std::make_shared<EntityFactory>(managerWrapper->getEntityManager() , managerWrapper->getComponentManager());
    std::shared_ptr<SystemManager> systemManager = std::make_shared<SystemManager>(managerWrapper);

    systemManager->addSystem(std::make_shared<DisplaySystem>(managerWrapper, systemManager->getEntitiesToDelete()));
    isPlaying = true;
    factory->addEntityConstructor(std::make_shared<TestEntity>());
    factory->createEntity("Test");
    factory->createEntity("Test");
    factory->createEntity("Test");
    managerWrapper->getRenderManager()->init();
    while (isPlaying == true) {
        managerWrapper->getRenderManager()->graphicsUpdate();
        systemManager->updateAll();
        isPlaying = managerWrapper->getRenderManager()->eventUpdate();
    }
    managerWrapper->getRenderManager()->terminate();
    return 0;
}
