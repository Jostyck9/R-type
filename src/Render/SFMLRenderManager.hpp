/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** SFMLRenderManager.hpp
*/

#ifndef R_TYPE_SFMLRENDERMANAGER_H
#define R_TYPE_SFMLRENDERMANAGER_H

#include "IRenderManager.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <RtypeResources.hpp>
#include "Input.hpp"
#include "Color.hpp"

namespace ecs
{
/**
     * @brief Manager gameRendering of the game
     *
     */
    class SFMLRenderManager : public IRenderManager {
    public:
        SFMLRenderManager(std::shared_ptr<ResourceManager> &rtypeResources);
        ~SFMLRenderManager();
        /**
         * @brief initialize sfml window etc
         *
         */
    void init() override;
    void terminate() override;

    /**
         * @brief display a graphical component
         *
         */
    void graphicsUpdate(std::shared_ptr<components::Sprite> &sprite, std::shared_ptr<components::Position> &pos) override;

    /**
         * @brief update text component
         *
         */
    void textUpdate(std::shared_ptr<components::Text> &Text, std::shared_ptr<components::Position> &pos) override;
    /**
         * @brief update event and return type of event
         *
         */
    bool eventUpdate() override;
    /**
         * @brief clear the window of all rendered objects
         *
         */
    void clear() override;
    /**
         * @brief displayy the window and all rendered objects
         *
         */
    void display() override;
    /**
         * @brief update what key are pressed
         *
         */
     void updatePressedKeys();

     std::map<ecs::input::Key, KEY_STATE> &getKeysMap() override;
     
private:
    sf::RenderWindow _window;             /*!< Internal window used by SFML functions */
    sf::Music _music;                     /*!<Music of the program */
    sf::Event _event;                     /*!<Events of the program */
    sf::Sprite _sprite;                   /*!<Sprite of the program */
    std::map<ecs::Color, sf::Color> _colors; /*!<Color mapping*/
    sf::Texture _texture;                 /*!<Texture of the program */
    std::shared_ptr<ResourceManager> _rtypeResources;
    sf::RectangleShape _rectangle; /*!<Shape of the program */
    sf::Font _font;                /*!<Font of the program */
    sf::Text _text;                /*<Text of the program */
    sf::IntRect _rect;
    std::map<sf::Keyboard::Key, ecs::input::Key> _keys; /*!<Key mapping*/
    std::map<ecs::input::Key, KEY_STATE> _keysMap; /*<Contains name of key and if it is pressed or not */
};
} // namespace ecs

#endif //R_TYPE_RENDERMANAGER_H
