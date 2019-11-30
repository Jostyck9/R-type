//
// Created by romane on 26/11/2019.
//

#include "RtypeResources.hpp"

namespace ecs {

    RtypeResources::RtypeResources() : ResourceManager()
    {
        try {
            loadTexture("gameBackground", "./resources/background.png");
            loadTexture("test", "./resources/r-typesheet1.gif");
            loadTexture("player", "./resources/player.png");
            loadTexture("bullet", "./resources/bullet.png");
            loadTexture("ennemy", "./resources/ennemy01.png");
            loadTexture("ennemyType01", "./resources/ennemytype01.png");
            loadTexture("backgroundMenu", "./resources/menu_background.png");
            loadTexture("backgroundWithoutTitle", "./resources/background_without_title.png");
            loadFont("Pixeled", "./resources/font.ttf");
        } catch (const std::exception &e) {
            throw e;
        }
    }
}