//
// Created by romane on 28/11/2019.
//

#ifndef R_TYPE_MENUSCENE_HPP
#define R_TYPE_MENUSCENE_HPP

#include "Ecs.hpp"
#include "IEntityFactory.hpp"
#include "IScene.hpp"

namespace ecs {
    class MenuScene : public IScene {
    public:
        MenuScene(std::shared_ptr<Ecs> &ecs);

        ~MenuScene() = default;
    private:
        std::shared_ptr<Ecs> &_ecs;
    };
}

#endif //R_TYPE_MENUSCENE_HPP
