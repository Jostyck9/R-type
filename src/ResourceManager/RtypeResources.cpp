//
// Created by romane on 26/11/2019.
//

#include "RtypeResources.hpp"

namespace ecs {

    RtypeResources::RtypeResources() : ResourceManager()
    {
        try {
            loadTexture("background", "../resources/background.png");
            loadTexture("test", "../resources/r-typesheet1.gif");        
            loadTexture("player", "../resources/player.png");
        } catch (const std::exception &e) {
            throw e;
        }
    }
}