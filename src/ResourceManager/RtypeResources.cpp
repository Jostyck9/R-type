//
// Created by romane on 26/11/2019.
//

#include "RtypeResources.hpp"

namespace ecs {

    RtypeResources::RtypeResources() : ResourceManager()
    {
        try {
            loadTexture("background-parallax", "./resources/parallax-background.png");
            loadTexture("planet-parallax", "./resources/parallax-planet.png");
            loadTexture("far-planet-parallax", "./resources/parallax-far-planets.png");
            loadTexture("space-stars-parallax", "./resources/parallax-space-stars.png");
            loadTexture("ring-planet-parallax", "./resources/parallax-ring-planet.png");
            loadTexture("test", "./resources/r-typesheet1.gif");
            loadTexture("player", "./resources/player.png");
            loadTexture("bullet", "./resources/bullet.png");
            loadTexture("ennemy", "./resources/ennemy01.png");
            loadTexture("ennemyType01", "./resources/ennemytype01.png");
            loadTexture("backgroundMenu", "./resources/menu_background.png");
            loadFont("Pixeled", "./resources/font.ttf");
        } catch (const std::exception &e) {
            throw e;
        }
    }
}