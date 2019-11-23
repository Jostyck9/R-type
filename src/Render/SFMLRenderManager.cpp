
#include "SFMLRenderManager.hpp"

namespace ecs {

    SFMLRenderManager::SFMLRenderManager() : _window(nullptr)
    {
        _keys[sf::Keyboard::A] = arcade::input::A;
        _keys[sf::Keyboard::B] = arcade::input::B;
        _keys[sf::Keyboard::C] = arcade::input::C;
        _keys[sf::Keyboard::D] = arcade::input::D;
        _keys[sf::Keyboard::E] = arcade::input::E;
        _keys[sf::Keyboard::F] = arcade::input::F;
        _keys[sf::Keyboard::G] = arcade::input::G;
        _keys[sf::Keyboard::H] = arcade::input::H;
        _keys[sf::Keyboard::I] = arcade::input::I;
        _keys[sf::Keyboard::J] = arcade::input::J;
        _keys[sf::Keyboard::K] = arcade::input::K;
        _keys[sf::Keyboard::L] = arcade::input::L;
        _keys[sf::Keyboard::M] = arcade::input::M;
        _keys[sf::Keyboard::N] = arcade::input::N;
        _keys[sf::Keyboard::O] = arcade::input::O;
        _keys[sf::Keyboard::P] = arcade::input::P;
        _keys[sf::Keyboard::Q] = arcade::input::Q;
        _keys[sf::Keyboard::R] = arcade::input::R;
        _keys[sf::Keyboard::S] = arcade::input::S;
        _keys[sf::Keyboard::T] = arcade::input::T;
        _keys[sf::Keyboard::U] = arcade::input::U;
        _keys[sf::Keyboard::V] = arcade::input::V;
        _keys[sf::Keyboard::W] = arcade::input::W;
        _keys[sf::Keyboard::X] = arcade::input::X;
        _keys[sf::Keyboard::Y] = arcade::input::Y;
        _keys[sf::Keyboard::Z] = arcade::input::Z;
        _keys[sf::Keyboard::Add] = arcade::input::ADD;
        _keys[sf::Keyboard::LAlt] = arcade::input::LEFT_ALT;
        _keys[sf::Keyboard::RAlt] = arcade::input::RIGHT_ALT;
        _keys[sf::Keyboard::LControl] = arcade::input::LEFT_CONTROL;
        _keys[sf::Keyboard::RControl] = arcade::input::RIGHT_CONTROL;
        _keys[sf::Keyboard::LShift] = arcade::input::LEFT_SHIFT;
        _keys[sf::Keyboard::RShift] = arcade::input::RIGHT_SHIFT;
        _keys[sf::Keyboard::LSystem] = arcade::input::LEFT_SYSTEM;
        _keys[sf::Keyboard::RSystem] = arcade::input::RIGHT_SYSTEM;
        _keys[sf::Keyboard::LBracket] = arcade::input::LEFT_BRACKET;
        _keys[sf::Keyboard::RBracket] = arcade::input::RIGHT_BRACKET;
        _keys[sf::Keyboard::BackSlash] = arcade::input::BACKSLASH;
        _keys[sf::Keyboard::BackSpace] = arcade::input::BACKSPACE;
        _keys[sf::Keyboard::Comma] = arcade::input::COMMA;
        _keys[sf::Keyboard::Num0] = arcade::input::D0;
        _keys[sf::Keyboard::Num1] = arcade::input::D1;
        _keys[sf::Keyboard::Num2] = arcade::input::D2;
        _keys[sf::Keyboard::Num3] = arcade::input::D3;
        _keys[sf::Keyboard::Num4] = arcade::input::D4;
        _keys[sf::Keyboard::Num5] = arcade::input::D5;
        _keys[sf::Keyboard::Num6] = arcade::input::D6;
        _keys[sf::Keyboard::Num7] = arcade::input::D7;
        _keys[sf::Keyboard::Num8] = arcade::input::D8;
        _keys[sf::Keyboard::Num9] = arcade::input::D9;
        _keys[sf::Keyboard::Numpad0] = arcade::input::NUM0;
        _keys[sf::Keyboard::Numpad1] = arcade::input::NUM1;
        _keys[sf::Keyboard::Numpad2] = arcade::input::NUM2;
        _keys[sf::Keyboard::Numpad3] = arcade::input::NUM3;
        _keys[sf::Keyboard::Numpad4] = arcade::input::NUM4;
        _keys[sf::Keyboard::Numpad5] = arcade::input::NUM5;
        _keys[sf::Keyboard::Numpad6] = arcade::input::NUM6;
        _keys[sf::Keyboard::Numpad7] = arcade::input::NUM7;
        _keys[sf::Keyboard::Numpad8] = arcade::input::NUM8;
        _keys[sf::Keyboard::Numpad9] = arcade::input::NUM9;
        _keys[sf::Keyboard::Delete] = arcade::input::DELETE;
        _keys[sf::Keyboard::Divide] = arcade::input::DIVIDE;
        _keys[sf::Keyboard::Down] = arcade::input::DOWN;
        _keys[sf::Keyboard::Up] = arcade::input::UP;
        _keys[sf::Keyboard::Left] = arcade::input::LEFT;
        _keys[sf::Keyboard::Right] = arcade::input::RIGHT;
        _keys[sf::Keyboard::End] = arcade::input::END;
        #if SFML_VERSION_MINOR >= 5
        _keys[sf::Keyboard::Enter] = arcade::input::ENTER;
        #else
        _keys[sf::Keyboard::Return] = arcade::input::ENTER;
        #endif
        _keys[sf::Keyboard::Equal] = arcade::input::EQUAL;
        _keys[sf::Keyboard::Escape] = arcade::input::ESCAPE;
        _keys[sf::Keyboard::F1] = arcade::input::F1;
        _keys[sf::Keyboard::F2] = arcade::input::F2;
        _keys[sf::Keyboard::F3] = arcade::input::F3;
        _keys[sf::Keyboard::F4] = arcade::input::F4;
        _keys[sf::Keyboard::F5] = arcade::input::F5;
        _keys[sf::Keyboard::F6] = arcade::input::F6;
        _keys[sf::Keyboard::F7] = arcade::input::F7;
        _keys[sf::Keyboard::F8] = arcade::input::F8;
        _keys[sf::Keyboard::F9] = arcade::input::F9;
        _keys[sf::Keyboard::F10] = arcade::input::F10;
        _keys[sf::Keyboard::F11] = arcade::input::F11;
        _keys[sf::Keyboard::F12] = arcade::input::F12;
        _keys[sf::Keyboard::Home] = arcade::input::HOME;
        _keys[sf::Keyboard::Insert] = arcade::input::INSERT;
        _keys[sf::Keyboard::Multiply] = arcade::input::MULTIPLY;
        _keys[sf::Keyboard::PageUp] = arcade::input::PAGE_UP;
        _keys[sf::Keyboard::PageDown] = arcade::input::PAGE_DOWN;
        _keys[sf::Keyboard::Pause] = arcade::input::PAUSE;
        _keys[sf::Keyboard::Period] = arcade::input::PERIOD;
        _keys[sf::Keyboard::Quote] = arcade::input::QUOTE;
        _keys[sf::Keyboard::Return] = arcade::input::RETURN;
        _keys[sf::Keyboard::SemiColon] = arcade::input::SEMICOLON;
        _keys[sf::Keyboard::Space] = arcade::input::SPACE;
        _keys[sf::Keyboard::Subtract] = arcade::input::SUBTRACT;
        _keys[sf::Keyboard::Tab] = arcade::input::TAB;

        _colors[arcade::Color::BLACK] = sf::Color::Black;
        _colors[arcade::Color::WHITE] = sf::Color::White;
        _colors[arcade::Color::BLUE] = sf::Color::Blue;
        _colors[arcade::Color::RED] = sf::Color::Red;
        _colors[arcade::Color::GREEN] = sf::Color::Green;
        _colors[arcade::Color::YELLOW] = sf::Color::Yellow;
        _colors[arcade::Color::MAGENTA] = sf::Color::Magenta;
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

    void SFMLRenderManager::graphicsUpdate(Entity &entity)
    {
    _sprite = Sprite(//get la texture de l'entity);
        //Render un sprite dans la window --> besoin de la window, de la texture et du sprite en question de sa pos etc
    _sprite.setPosition(entity.getPosX(), entity.getPosY());
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

    void SFMLRenderManager::clear() {
            _window->clear();
    }
}
