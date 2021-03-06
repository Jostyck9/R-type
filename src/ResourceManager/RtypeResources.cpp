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
            loadTexture("playerTwo", "./resources/playerTwo.png");
            loadTexture("bullet", "./resources/bullet.png");
            loadTexture("enemyBullet", "./resources/enemyBullet.png");
            loadTexture("enemyType02", "./resources/enemytype02.png");
            loadTexture("enemyType03", "./resources/enemytype03.png");
            loadTexture("enemyType01", "./resources/enemytype01.png");
            loadTexture("enemy", "./resources/enemy01.png");
            loadTexture("backgroundMenu", "./resources/menu_background.png");
            loadTexture("backgroundWithoutTitle", "./resources/background_without_title.png");
            loadFont("Pixeled", "./resources/font.ttf");
            loadMusic("GameMusic", "./resources/music.ogg");
            loadSound("laser", "./resources/laser.wav");
        } catch (const std::exception &e) {
            throw e;
        }
    }
}