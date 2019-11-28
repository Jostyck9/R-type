//
// Created by romane on 28/11/2019.
//

#ifndef R_TYPE_SCENEMANAGER_HPP
#define R_TYPE_SCENEMANAGER_HPP

#include <memory>
#include <ManagerWrapper.hpp>
#include "IScene.hpp"
#include "ISystemManager.hpp"
#include "IEntityFactory.hpp"

namespace ecs {
    /**
     * @brief Scene Manager for the game
     *
     */
    class SceneManager {
    public:
        SceneManager();
        ~SceneManager() = default;

        void createMenu();
        void run();

    private:
        std::shared_ptr<IScene> _current;
        std::shared_ptr<ManagerWrapper> _managerWrapper;
        std::shared_ptr<system::ISystemManager> _systemManager;
        std::shared_ptr<entities::IEntityFactory> _entityFactory;
    };
}

#endif //R_TYPE_SCENEMANAGER_HPP
