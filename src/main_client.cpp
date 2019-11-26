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
    std::shared_ptr<ecs::ManagerWrapper> managerWrapper = std::make_shared<ManagerWrapper>();
    std::shared_ptr<IEntityFactory> factory = std::make_shared<EntityFactory>(managerWrapper->getEntityManager() , managerWrapper->getComponentManager());
    std::shared_ptr<SystemManager> systemManager = std::make_shared<SystemManager>(std::shared_ptr<WrapperManager> );

    systemManager->addSystem(std::make_shared<DisplaySystem>(managerWrapper);
    isPlaying = true;
    factory->addEntityConstructor(std::make_shared<TestEntity>());
    factory->createEntity("Test");
    factory->createEntity("Test");
    factory->createEntity("Test");
    render->init();
    while (isPlaying == true) {
        render->graphicsUpdate();
        systemManager->updateAll();
        isPlaying = render->eventUpdate();
    }
    render->terminate();
    return 0;
}
