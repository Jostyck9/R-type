/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** GameScene.hpp
*/

#ifndef R_TYPE_GAMESCENE_HPP
#define R_TYPE_GAMESCENE_HPP

#include "Ecs.hpp"
#include "IEntityFactory.hpp"
#include "IScene.hpp"

namespace ecs {
    class GameScene : public IScene {
    public:
        GameScene(std::shared_ptr<Ecs> &ecs);

        ~GameScene() = default;
    private:
        std::shared_ptr<Ecs> &_ecs;
    };
}

#endif //R_TYPE_GAMESCENE_HPP
