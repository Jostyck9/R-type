//
// Created by romane on 25/11/2019.
//

#include "IEntityManager.hpp"
#include "IEntityFactory.hpp"
#include "IComponentManager.hpp"
#include "ISystemManager.hpp"
#include "IRenderManager.hpp"
#include "ManagerWrapper.hpp"
#include "SystemManager.hpp"
#include "RtypeResources.hpp"
#include "SceneManager.hpp"

#ifndef R_TYPE_RTYPE_HPP
#define R_TYPE_RTYPE_HPP

using namespace ecs::components;
using namespace ecs::system;
using namespace ecs::entities;
using namespace ecs;

class Rtype {
public:
    Rtype();
    ~Rtype() = default;

    void start();

private:
    std::shared_ptr<SceneManager> _sceneManager;
};

#endif //R_TYPE_RTYPE_HPP
