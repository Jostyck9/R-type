//
// Created by romane on 28/11/2019.
//

#ifndef R_TYPE_MENUSCENE_HPP
#define R_TYPE_MENUSCENE_HPP

#include <ManagerWrapper.hpp>
#include "IEntityFactory.hpp"
#include "IScene.hpp"

namespace ecs {
    class MenuScene : public IScene {
    public:
        MenuScene(const std::shared_ptr<ecs::ManagerWrapper>& managerWrapper,
                  const std::shared_ptr<ecs::system::ISystemManager>& systemManager,
                  const std::shared_ptr<ecs::entities::IEntityFactory>& entityFactory);

        ~MenuScene() = default;
    private:
        std::shared_ptr<entities::IEntityFactory> _entityFactory;
        std::shared_ptr<ecs::ManagerWrapper> _managerWrapper;
        std::shared_ptr<ecs::system::ISystemManager> _systemManager;
        std::shared_ptr<entities::IEntityManager> _entityManager;
    };
}

#endif //R_TYPE_MENUSCENE_HPP
