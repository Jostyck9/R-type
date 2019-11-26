#ifndef R_TYPE_SFMLRENDERMANAGER_H
#define R_TYPE_SFMLRENDERMANAGER_H

#include "IRenderManager.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Input.hpp"

namespace ecs {
    /**
     * @brief Manager gameRendering of the game
     *
     */
    class SFMLRenderManager : public IRenderManager {
    public:
        SFMLRenderManager();
        ~SFMLRenderManager();
        /**
         * @brief Get the instance of the RenderManager classe
         *
         * @return SFMLRenderManager
         */
        // static SFMLRenderManager &getInstance();

        // SFMLRenderManager(const SFMLRenderManager &) = delete;
        // SFMLRenderManager operator=(const SFMLRenderManager &) = delete;
        
        /**
         * @brief initialize sfml window etc
         *
         */
        void init() override;
        void terminate() override;
        /**
         * @brief update a graphical objet
         *
         */
        void graphicsUpdate() override;
        /**
         * @brief update audio
         *
         */
        void audioUpdate() override;
        /**
         * @brief update text component
         *
         */
        void textUpdate() override;
        /**
         * @brief update event and return type of event
         *
         */
        bool eventUpdate() override;
        /**
         * @brief clear the window of all rendered objects
         *
         */
        void clear();
      
    private:
        sf::RenderWindow *_window; /*!< Internal window used by SFML functions */
        sf::Music _music; /*!<Music of the program */
        sf::Event _event; /*!<Events of the program */
        int aled;
        sf::Sprite _sprite; /*!<Sprite of the program */
        std::map<int, ecs::input::Key> _keys; /*!<Key mapping*/
        sf::Texture texture;
    };
}

#endif //R_TYPE_RENDERMANAGER_H