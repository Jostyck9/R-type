/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** main_dlloader.cpp
*/

#include "EntityManager.hpp"
//#include "EntityFactory.hpp"
#include "ComponentManager.hpp"
#include "SystemManager.hpp"
//#include "DisplaySystem.hpp"
#include "Position.hpp"
#include "IRenderManager.hpp"
#include "SFMLRenderManager.hpp"
#include "ManagerWrapper.hpp"
#include "DlLoader.hpp"
#include "ISystemConstructor.hpp"
#include "SystemConstructor.hpp"
// #include "TestEntity2.hpp"

using namespace ecs::components;
using namespace ecs::entities;
using namespace ecs::system;
using namespace ecs;

int main()
{
    // DlLoader<TestEntity2> displaySystem;

    // displaySystem.loadInstance("./build/lib/libTestEntity2.so"); //undefined symbol

    // std::shared_ptr<ecs::ManagerWrapper> managerWrapper = std::make_shared<ecs::ManagerWrapper>();
    // std::shared_ptr<SystemManager> systemManager = std::make_shared<SystemManager>(managerWrapper);

    // auto test = displaySystem.getInstance();

    // std::string test2 = test->create(managerWrapper, systemManager->getEntitiesToDelete())->getName();
    // systemManager->addSystem(test);
    // systemManager->updateAll();
    return 0;
}