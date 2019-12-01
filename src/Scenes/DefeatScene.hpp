//
// Created by romane on 28/11/2019.
//

#ifndef R_TYPE_DEFEATCENE_HPP
#define R_TYPE_DEFEATCENE_HPP

#include "Ecs.hpp"
#include "IEntityFactory.hpp"
#include "IScene.hpp"

namespace ecs {
    class DefeatScene : public IScene {
    public:
        DefeatScene(std::shared_ptr<Ecs> &ecs);

        ~DefeatScene() = default;
    private:
        std::shared_ptr<Ecs> &_ecs;
    };
}

#endif //R_TYPE_DEFEATCENE_HPP
