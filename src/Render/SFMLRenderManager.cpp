/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** SFMLRenderManager.cpp
*/

#include <iostream>
#include "SFMLRenderManager.hpp"
#include "RTypeExceptions.hpp"

namespace ecs
{

SFMLRenderManager::SFMLRenderManager(std::shared_ptr<ResourceManager> &rtypeResources) : _event(), _rtypeResources(rtypeResources), _rectangle(sf::Vector2f(120, 50)), _rect(0, 0, 0, 0) 
{
    _keys[sf::Keyboard::A] = ecs::input::A;
    _keys[sf::Keyboard::B] = ecs::input::B;
    _keys[sf::Keyboard::C] = ecs::input::C;
    _keys[sf::Keyboard::D] = ecs::input::D;
    _keys[sf::Keyboard::E] = ecs::input::E;
    _keys[sf::Keyboard::F] = ecs::input::F;
    _keys[sf::Keyboard::G] = ecs::input::G;
    _keys[sf::Keyboard::H] = ecs::input::H;
    _keys[sf::Keyboard::I] = ecs::input::I;
    _keys[sf::Keyboard::J] = ecs::input::J;
    _keys[sf::Keyboard::K] = ecs::input::K;
    _keys[sf::Keyboard::L] = ecs::input::L;
    _keys[sf::Keyboard::M] = ecs::input::M;
    _keys[sf::Keyboard::N] = ecs::input::N;
    _keys[sf::Keyboard::O] = ecs::input::O;
    _keys[sf::Keyboard::P] = ecs::input::P;
    _keys[sf::Keyboard::Q] = ecs::input::Q;
    _keys[sf::Keyboard::R] = ecs::input::R;
    _keys[sf::Keyboard::S] = ecs::input::S;
    _keys[sf::Keyboard::T] = ecs::input::T;
    _keys[sf::Keyboard::U] = ecs::input::U;
    _keys[sf::Keyboard::V] = ecs::input::V;
    _keys[sf::Keyboard::W] = ecs::input::W;
    _keys[sf::Keyboard::X] = ecs::input::X;
    _keys[sf::Keyboard::Y] = ecs::input::Y;
    _keys[sf::Keyboard::Z] = ecs::input::Z;
    _keys[sf::Keyboard::Add] = ecs::input::ADD;
    _keys[sf::Keyboard::LAlt] = ecs::input::LEFT_ALT;
    _keys[sf::Keyboard::RAlt] = ecs::input::RIGHT_ALT;
    _keys[sf::Keyboard::LControl] = ecs::input::LEFT_CONTROL;
    _keys[sf::Keyboard::RControl] = ecs::input::RIGHT_CONTROL;
    _keys[sf::Keyboard::LShift] = ecs::input::LEFT_SHIFT;
    _keys[sf::Keyboard::RShift] = ecs::input::RIGHT_SHIFT;
    _keys[sf::Keyboard::LSystem] = ecs::input::LEFT_SYSTEM;
    _keys[sf::Keyboard::RSystem] = ecs::input::RIGHT_SYSTEM;
    _keys[sf::Keyboard::LBracket] = ecs::input::LEFT_BRACKET;
    _keys[sf::Keyboard::RBracket] = ecs::input::RIGHT_BRACKET;
    _keys[sf::Keyboard::BackSlash] = ecs::input::BACKSLASH;
    _keys[sf::Keyboard::BackSpace] = ecs::input::BACKSPACE;
    _keys[sf::Keyboard::Comma] = ecs::input::COMMA;
    _keys[sf::Keyboard::Num0] = ecs::input::D0;
    _keys[sf::Keyboard::Num1] = ecs::input::D1;
    _keys[sf::Keyboard::Num2] = ecs::input::D2;
    _keys[sf::Keyboard::Num3] = ecs::input::D3;
    _keys[sf::Keyboard::Num4] = ecs::input::D4;
    _keys[sf::Keyboard::Num5] = ecs::input::D5;
    _keys[sf::Keyboard::Num6] = ecs::input::D6;
    _keys[sf::Keyboard::Num7] = ecs::input::D7;
    _keys[sf::Keyboard::Num8] = ecs::input::D8;
    _keys[sf::Keyboard::Num9] = ecs::input::D9;
    _keys[sf::Keyboard::Numpad0] = ecs::input::NUM0;
    _keys[sf::Keyboard::Numpad1] = ecs::input::NUM1;
    _keys[sf::Keyboard::Numpad2] = ecs::input::NUM2;
    _keys[sf::Keyboard::Numpad3] = ecs::input::NUM3;
    _keys[sf::Keyboard::Numpad4] = ecs::input::NUM4;
    _keys[sf::Keyboard::Numpad5] = ecs::input::NUM5;
    _keys[sf::Keyboard::Numpad6] = ecs::input::NUM6;
    _keys[sf::Keyboard::Numpad7] = ecs::input::NUM7;
    _keys[sf::Keyboard::Numpad8] = ecs::input::NUM8;
    _keys[sf::Keyboard::Numpad9] = ecs::input::NUM9;
    _keys[sf::Keyboard::Delete] = ecs::input::DELETEKEY;
    _keys[sf::Keyboard::Divide] = ecs::input::DIVIDE;
    _keys[sf::Keyboard::Down] = ecs::input::DOWN;
    _keys[sf::Keyboard::Up] = ecs::input::UP;
    _keys[sf::Keyboard::Left] = ecs::input::LEFT;
    _keys[sf::Keyboard::Right] = ecs::input::RIGHT;
    _keys[sf::Keyboard::End] = ecs::input::END;
#if SFML_VERSION_MINOR >= 5
    _keys[sf::Keyboard::Enter] = ecs::input::ENTER;
#else
    _keys[sf::Keyboard::Return] = ecs::input::ENTER;
#endif
    _keys[sf::Keyboard::Equal] = ecs::input::EQUAL;
    _keys[sf::Keyboard::Escape] = ecs::input::ESCAPE;
    _keys[sf::Keyboard::F1] = ecs::input::F1;
    _keys[sf::Keyboard::F2] = ecs::input::F2;
    _keys[sf::Keyboard::F3] = ecs::input::F3;
    _keys[sf::Keyboard::F4] = ecs::input::F4;
    _keys[sf::Keyboard::F5] = ecs::input::F5;
    _keys[sf::Keyboard::F6] = ecs::input::F6;
    _keys[sf::Keyboard::F7] = ecs::input::F7;
    _keys[sf::Keyboard::F8] = ecs::input::F8;
    _keys[sf::Keyboard::F9] = ecs::input::F9;
    _keys[sf::Keyboard::F10] = ecs::input::F10;
    _keys[sf::Keyboard::F11] = ecs::input::F11;
    _keys[sf::Keyboard::F12] = ecs::input::F12;
    _keys[sf::Keyboard::Home] = ecs::input::HOME;
    _keys[sf::Keyboard::Insert] = ecs::input::INSERT;
    _keys[sf::Keyboard::Multiply] = ecs::input::MULTIPLY;
    _keys[sf::Keyboard::PageUp] = ecs::input::PAGE_UP;
    _keys[sf::Keyboard::PageDown] = ecs::input::PAGE_DOWN;
    _keys[sf::Keyboard::Pause] = ecs::input::PAUSE;
    _keys[sf::Keyboard::Period] = ecs::input::PERIOD;
    _keys[sf::Keyboard::Quote] = ecs::input::QUOTE;
    _keys[sf::Keyboard::Return] = ecs::input::RETURN;
    _keys[sf::Keyboard::SemiColon] = ecs::input::SEMICOLON;
    _keys[sf::Keyboard::Space] = ecs::input::SPACE;
    _keys[sf::Keyboard::Subtract] = ecs::input::SUBTRACT;
    _keys[sf::Keyboard::Tab] = ecs::input::TAB;
    
    _colors[ecs::Color::BLACK] = sf::Color::Black;
    _colors[ecs::Color::WHITE] = sf::Color::White;
    _colors[ecs::Color::RED] = sf::Color::Red;
    _colors[ecs::Color::BLUE] = sf::Color::Blue;
    _colors[ecs::Color::GREEN] = sf::Color::Green;
    _colors[ecs::Color::YELLOW] = sf::Color::Yellow;
    _colors[ecs::Color::MAGENTA] = sf::Color::Magenta;
    _rectangle.setFillColor(sf::Color(100, 250, 50));
    _text.setFillColor(_colors[ecs::Color::WHITE]);
    _text.setFont(_font);
    _font = _rtypeResources->getFont("Pixeled")->getSFMLFont();
    for (auto &key : _keys) {
        _keysMap[key.second] = NONE;
    }
}

SFMLRenderManager::~SFMLRenderManager()
{
    terminate();
}

void SFMLRenderManager::init()
{
	_window.create(sf::VideoMode(1500, 900), "R-Type");
    _window.setFramerateLimit(60);
    _window.clear();
    _window.display();
}

void SFMLRenderManager::terminate()
{
    _window.close();
    //stop audio ?
}

std::map<ecs::input::Key, IRenderManager::KEY_STATE> &SFMLRenderManager::getKeysMap()
{
    return _keysMap;
}

void SFMLRenderManager::updatePressedKeys()
{
    for (auto &key : _keysMap)
    {
        for (auto &it : _keys)
        {
            if (it.second == key.first)
            {
                if (!sf::Keyboard::isKeyPressed(it.first)) {
                    if (key.second == PRESSED) {
                        key.second = RELEASED;
                    } else {
                        key.second = NONE;
                    }
                } else {
                    key.second = PRESSED;
                }
            }
        }
    }
}

void SFMLRenderManager::graphicsUpdate(std::shared_ptr<components::Sprite> &sprite, std::shared_ptr<components::Position> &pos)
{
    _rect.height = sprite->getRect().getHeight();
    _rect.width = sprite->getRect().getWidth();
    _rect.top = sprite->getRect().getPosY();
    _rect.left = sprite->getRect().getPosX();
    if (sprite == nullptr)
        return;
    try
    {
        _texture = _rtypeResources->getTexture(sprite->getName())->getSFMLTexture();
        _texture.setRepeated(true);
        _sprite.setTexture(_texture);
        _sprite.setTextureRect(_rect);
        _sprite.setPosition(pos->getX(), pos->getY());
        _window.draw(_sprite);
    }
    catch (const RTypeExceptions &e)
    {
        std::cerr << e.what() << e.where() << std::endl;
        _rectangle.setPosition(pos->getX(), pos->getY());
        _window.draw(_rectangle);
    }
}

void SFMLRenderManager::textUpdate(std::shared_ptr<components::Text> &Text, std::shared_ptr<components::Position> &pos)
{
    _text.setFillColor(_colors[Text->getColor()]);
    _text.setString(Text->getStr());
    _text.setCharacterSize(Text->getSize());
    _text.setPosition(pos->getX() + Text->getPostion().first, pos->getY() + Text->getPostion().second);
    _window.draw(_text);
}

bool SFMLRenderManager::eventUpdate()
{
    while (_window.pollEvent(_event))
    {
        if (_event.type == sf::Event::Closed)
        {
            _window.close();
            return false;
        }
    }
    updatePressedKeys();
    return true;
}

void SFMLRenderManager::clear()
{
    _window.clear();
}

void SFMLRenderManager::display()
{
    _window.display();
}

ecs::network::PacketManager SFMLRenderManager::getKeyToPacket()
{
    ecs::network::PacketManager toFill;

    toFill.setCmd(ecs::network::PacketManager::UPDATE);
    for (auto &it : _keysMap) {
        if (it.second == PRESSED) {
            if (toFill.addKey(it.first) == -1)
                return toFill;
        }
    }
    return toFill;
}

} // namespace ecs