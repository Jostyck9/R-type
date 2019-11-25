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

using namespace ecs::components;
using namespace ecs::system;
using namespace ecs::entities;

int main()
{
    bool isPlaying = false;
	ecs::SFMLRenderManager render;
    std::shared_ptr<IComponentManager> componentManager = std::make_shared<ComponentManager>();
    std::shared_ptr<IEntityManager> entityManager = std::make_shared<EntityManager>(componentManager);
    std::shared_ptr<SystemManager> systemManager = std::make_shared<SystemManager>(entityManager, componentManager);
    std::shared_ptr<IEntityFactory> factory = std::make_shared<EntityFactory>(entityManager, componentManager);
	// ecs::SFMLRenderManager* render = new ecs::SFMLRenderManager();
    // std::shared_ptr<IRenderManager> render = std::make_shared<SFMLRenderManager>();

    systemManager->setRenderManager(&render);
    isPlaying = true;
    factory->addEntityConstructor(std::make_shared<TestEntity>());
    factory->createEntity("Test");
    factory->createEntity("Test");
    factory->createEntity("Test");
    render.init();
    render.graphicsUpdate();
    while (isPlaying == true) {
        isPlaying = render.eventUpdate();
        systemManager->updateAll();
    }
    render.terminate();
    return 0;
}
