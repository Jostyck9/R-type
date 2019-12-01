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

        /**
         * @brief load the scene from a name
         * 
         * @param name
         */
        void loadScene(const std::string& name);
        /**
         * @brief Create a Menu object
         * 
         */
        void createMenu();
        /**
         * @brief Create a Defeat object
         *
         */
        void createDefeat();
        /**
         * @brief Create a Game object
         * 
         */
        void createGame();
        /**
         * @brief Create a Choose Room object
         * 
         */
        void createChooseRoom();
        /**
         * @brief run the scene manager
         * 
         */
        void run();

    private:
        std::shared_ptr<IScene> _current;
        std::shared_ptr<Ecs> _ecs;
    };
}

#endif //R_TYPE_SCENEMANAGER_HPP
