/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** main_client.cpp
*/

#include "EntityManager.hpp"
#include "EntityFactory.hpp"
#include "IEntityManager.hpp"
#include "TestEntity.hpp"
#include "TestEntity2.hpp"
#include "ComponentManager.hpp"
#include "ISystemConstructor.hpp"
#include "SystemManager.hpp"
#include "SystemFactory.hpp"
#include "ISystemFactory.hpp"
#include "Display/DisplaySystem.hpp"
#include "Physics/Position.hpp"
#include "IRenderManager.hpp"
#include "SFMLRenderManager.hpp"
#include "ManagerWrapper.hpp"
#include "DlLoader.hpp"
#include "ILoader.hpp"
#include  "EntitiesLoader.hpp"

using namespace ecs::components;
using namespace ecs::entities;
using namespace ecs::system;
using namespace ecs;

int main()
{
    bool isPlaying = false;

    DlLoader<ISystemConstructor> displaySystem;
    DlLoader<ISystemConstructor> movementSystem;
    DlLoader<TestEntity> testEntity;
    DlLoader<TestEntity2> testEntity2;

    EntitiesLoader test;

    test.loadAllLibrary();

    displaySystem.loadInstance("../lib/systems/libDisplaySystem.so");
    movementSystem.loadInstance("../lib/systems/libMovementSystem.so");
    testEntity2.loadInstance("../lib/entities/libTestEntity2.so");
    testEntity.loadInstance("../lib/entities/libTestEntity.so");

    std::shared_ptr<ecs::ManagerWrapper> managerWrapper = std::make_shared<ecs::ManagerWrapper>();
    std::shared_ptr<IEntityFactory> factory = std::make_shared<EntityFactory>(managerWrapper->getEntityManager() , managerWrapper->getComponentManager());
    std::shared_ptr<SystemManager> systemManager = std::make_shared<SystemManager>(managerWrapper);
    std::shared_ptr<ISystemFactory> sysFactory = std::make_shared<SystemFactory>(managerWrapper, systemManager);

    auto display = displaySystem.getInstance();
    auto movement = movementSystem.getInstance();

    sysFactory->addSystemConstructor(display);
    sysFactory->addSystemConstructor(movement);
    systemManager->addSystem(sysFactory->createSystem(display->create(managerWrapper, systemManager->getEntitiesToDelete())->getName()));
    systemManager->addSystem(sysFactory->createSystem(movement->create(managerWrapper, systemManager->getEntitiesToDelete())->getName()));

    isPlaying = true;
    auto test1 = testEntity.getInstance();
    auto test2 = testEntity2.getInstance();

    factory->addEntityConstructor(test1);
    factory->addEntityConstructor(test2);
    factory->createEntity("Test");
    factory->createEntity("Test2");
    managerWrapper->getRenderManager()->init();
    while (isPlaying == true) {
        managerWrapper->getRenderManager()->graphicsUpdate();
        systemManager->updateAll();
        isPlaying = managerWrapper->getRenderManager()->eventUpdate();
    }
    managerWrapper->getRenderManager()->terminate();
    return 0;
}
