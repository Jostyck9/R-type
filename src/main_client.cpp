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
#include "TestEntity2.hpp"
#include "Physics/Position.hpp"
#include "TestEntity.hpp"
#include "IRenderManager.hpp"
#include "SFMLRenderManager.hpp"
#include "ManagerWrapper.hpp"
#include "Serializer.hpp"

using namespace ecs::components;
using namespace ecs::entities;
using namespace ecs::system;

int main()
{
    // bool isPlaying = false;
    std::shared_ptr<ecs::ManagerWrapper> managerWrapper = std::make_shared<ecs::ManagerWrapper>();
    std::shared_ptr<IEntityFactory> factory = std::make_shared<EntityFactory>(managerWrapper->getEntityManager() , managerWrapper->getComponentManager());
    std::shared_ptr<SystemManager> systemManager = std::make_shared<SystemManager>(managerWrapper);

    systemManager->addSystem(std::make_shared<DisplaySystem>(managerWrapper, systemManager->getEntitiesToDelete()));
    systemManager->addSystem(std::make_shared<MovementSystem>(managerWrapper, systemManager->getEntitiesToDelete()));

    // isPlaying = true;
    factory->addEntityConstructor(std::make_shared<TestEntity>());
    factory->addEntityConstructor(std::make_shared<TestEntity2>());
    factory->createEntity("Test");
    factory->createEntity("Test2");
    // managerWrapper->getRenderManager()->init();
    // while (isPlaying == true) {
        // managerWrapper->getRenderManager()->graphicsUpdate();
        // systemManager->updateAll();
        // isPlaying = managerWrapper->getRenderManager()->eventUpdate();
    // }
    // managerWrapper->getRenderManager()->terminate();

    for (int i = 0; i < 10; i++) {
        systemManager->updateAll();
    }

    ecs::entities::Serializer serializer(managerWrapper->getEntityManager(), managerWrapper->getComponentManager());
    auto test = serializer.serialize();

    for (auto &it : test) {
        std::cout << it.id << std::endl;
        for (auto &it2 : it.components) {
            if (it2.type == ecs::network::ROTATION) {
                std::cout << "rotation : " << it2._rotation.radAngle << std::endl;
            } else {
                std::cout << "pos : " << it2._position.x << " " << it2._position.y << std::endl;
            }
        }
    }

    std::cout;
    return 0;
}
