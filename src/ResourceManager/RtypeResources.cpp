//
// Created by romane on 26/11/2019.
//

#include "RtypeResources.hpp"

namespace ecs {

    RtypeResources::RtypeResources()
    {
        try {
            loadTexture("background", "resources/background.png");
            loadTexture("test", "resources/r-typesheet1.gif");
        } catch (const std::exception &e) {
            throw e;
        }
    }
}