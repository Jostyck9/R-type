//
// Created by romane on 28/11/2019.
//

#ifndef R_TYPE_CHOOSEROOMSCENE_HPP
#define R_TYPE_CHOOSEROOMSCENE_HPP

#include "Ecs.hpp"
#include "IEntityFactory.hpp"
#include "IScene.hpp"

namespace ecs {
    class ChooseRoomScene : public IScene {
    public:
        ChooseRoomScene(std::shared_ptr<Ecs> &ecs);

        ~ChooseRoomScene() = default;
    private:
        std::shared_ptr<Ecs> &_ecs;
    };
}

#endif //R_TYPE_CHOOSEROOMSCENE_HPP
