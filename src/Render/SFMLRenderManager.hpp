
#ifndef R_TYPE_SFMLRENDERMANAGER_H
#define R_TYPE_SFMLRENDERMANAGER_H

#include "IRenderManager.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


namespace ecs {
    /**
     * @brief Manager gameRendering of the game
     * 
     */
    #define WIDTH 800
    #define HEIGHT 600
    class SFMLRenderManager : public IRenderManager {
    public:
        
        /**
         * @brief Get the instance of the RenderManager classe
         * 
         * @return SFMLRenderManager 
         */
        static SFMLRenderManager &getInstance();

        SFMLRenderManager(const SFMLRenderManager &) = delete;
        SFMLRenderManager operator=(const SFMLRenderManager &) = delete;
        void init() override;
        void terminate() override;
        void graphicsUpdate(Entity &entity) override;
        void audioUpdate() override;
        void textUpdate() override;
        void eventUpdate() override;
        /**
         * @brief clear the window of all rendered objects
         * 
         */
        void clear();
        //key and input handler ?
    private:
        SFMLRenderManager();
        ~SFMLRenderManager();

    public:
    private:
        sf::RenderWindow *_window; /*!< Internal window used by SFML functions */
        sf::Music _music; /*!<Music of the program */
        sf::Event _event; /*!<Events of the program */
        sf::Sprite _sprite; /*!<Sprite of the program */
    };
}

#endif //R_TYPE_RENDERMANAGER_H
