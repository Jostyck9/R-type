//
// Created by romane on 25/11/2019.
//

#include "IEntityManager.hpp"
#include "IEntityFactory.hpp"
#include "IComponentManager.hpp"
#include "ISystemManager.hpp"
#include "IRenderManager.hpp"

#ifndef R_TYPE_RTYPE_HPP
#define R_TYPE_RTYPE_HPP

using namespace ecs::components;
using namespace ecs::system;
using namespace ecs::entities;
using namespace ecs;

class Rtype {
public:
    Rtype();
    ~Rtype();

    void start();
    void stop();

private:
    std::shared_ptr<IComponentManager> _componentManager;
    std::shared_ptr<IEntityManager> _entityManager;
    std::shared_ptr<ISystemManager> _systemManager;
    std::shared_ptr<IEntityFactory> _entityFactory;
    std::shared_ptr<IRenderManager> _renderManager;
};

#endif //R_TYPE_RTYPE_HPP
