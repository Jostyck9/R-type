
#include "SFMLRenderManager.hpp"

namespace ecs {
           
    SFMLRenderManager::SFMLRenderManager() : _window(nullptr)
    {
    }
    
    SFMLRenderManager::~SFMLRenderManager()
    {
    }

    static SFMLRenderManager::SFMLRenderManager &getInstance();

    void SFMLRenderManager::init()
    {
    if (_window != nullptr)
        throw();
    _window = new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT, "RTYPE");
    if (_window == nullptr) {
        throw();
    }
    _window->setFramerateLimit(60);
        //init window audio etc
    }

    void SFMLRenderManager::terminate()
    {
    if (_window != nullptr) {
        _window->close();
        _window = nullptr;
    }
    //stop audio ?
    }

    void SFMLRenderManager::graphicsUpdate(ecs::)
    {
    _window->clear();
        //Render un sprite dans la window --> besoin de la window, de la texture et du sprite en question de sa pos etc
    _window->display();
    }

    void SFMLRenderManager::audioUpdate() 
    {
        // play/pause en fonction du state de l'audio
    }
    
    void SFMLRenderManager::textUpdate() 
    {
        //Render le texte dans la window --> besoin de window, texte , pos 
    }

    void SFMLRenderManager::eventUpdate() 
    {
        //update les event SFML ?
    }
}
