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
#include "DisplaySystem.hpp"
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

   displaySystem.loadInstance("./build/lib/systems/libDisplaySystem.so");
    movementSystem.loadInstance("./build/lib/systems/libMovementSystem.so");
    testEntity2.loadInstance("./build/lib/entities/libTestEntity2.so");
    testEntity.loadInstance("./build/lib/entities/libTestEntity.so");

    std::shared_ptr<ecs::ManagerWrapper> managerWrapper = std::make_shared<ecs::ManagerWrapper>();
    std::shared_ptr<IEntityFactory> factory = std::make_shared<EntityFactory>(managerWrapper->getEntityManager() , managerWrapper->getComponentManager());
    std::shared_ptr<SystemManager> systemManager = std::make_shared<SystemManager>(managerWrapper);
    std::shared_ptr<ISystemFactory> sysFactory = std::make_shared<SystemFactory>(managerWrapper, factory, systemManager);

    auto display = displaySystem.getInstance();
    auto movement = movementSystem.getInstance();
    sysFactory->addSystemConstructor(display);
    sysFactory->addSystemConstructor(movement);
    systemManager->addSystem(sysFactory->createSystem(display->create(managerWrapper, factory, systemManager->getEntitiesToDelete())->getName()));
    systemManager->addSystem(sysFactory->createSystem(movement->create(managerWrapper, factory, systemManager->getEntitiesToDelete())->getName()));

    isPlaying = true;
    auto test1 = testEntity.getInstance();
    auto test2 = testEntity2.getInstance();

    factory->addEntityConstructor(test1);
    factory->addEntityConstructor(test2);
    factory->createEntity("Test");
    factory->createEntity("Test2");
    managerWrapper->getRenderManager()->init();
    // while (isPlaying == true) {
    //     managerWrapper->getRenderManager()->graphicsUpdate();
    //     systemManager->updateAll();
    //     isPlaying = managerWrapper->getRenderManager()->eventUpdate();
    // }
    // return 0;
}

// #include <cstdlib>
// #include <cstring>
// #include <iostream>
// #include <boost/asio.hpp>
// #include <Client/UDPClient.hpp>
// #include <RTypeExceptions.hpp>
// #include "Rtype.hpp"

// int main(int ac, char **av)
// {

//     try {

//         if (ac != 3) {
//             std::cerr << "Usage: " << av[0] << " <host> <port>\n";
//             return 1;
//         }
//         Rtype rtype;
//         ecs::network::UDPClient clientNetwork(av[1], av[2]);
//         ecs::network::PacketManager packet;
//         packet.setCmd(ecs::network::PacketManager::HANDSHAKE);
//         // std::thread network([&]() {
//         //     clientNetwork.run();
//         // });
//         clientNetwork.send(packet);

//         packet.setCmd(ecs::network::PacketManager::ISALIVE);
//         rtype.start();
//         rtype.stop();

//     } catch (const RTypeExceptions &e) {
//         std::cerr << e.what() << std::endl;
//         std::cerr << "In file: " << e.where() << std::endl;
//     } catch (const std::exception &e) {
//         std::cerr << e.what();
//     }
//     return 0;
// }