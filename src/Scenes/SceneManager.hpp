//
// Created by romane on 28/11/2019.
//

#ifndef R_TYPE_SCENEMANAGER_HPP
#define R_TYPE_SCENEMANAGER_HPP

#include <memory>
#include "IScene.hpp"
#include "Ecs.hpp"

namespace ecs {
    /**
     * @brief Scene Manager for the game
     *
     */
    class SceneManager {
    public:
        SceneManager();
        ~SceneManager() = default;

        void loadScene(const std::string& name);
        void createMenu();
        void createGame();
        void createChooseRoom();
        void run();

    private:
        std::shared_ptr<IScene> _current;
        std::shared_ptr<Ecs> _ecs;
    };
}

#endif //R_TYPE_SCENEMANAGER_HPP
