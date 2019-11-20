//
// Created by romane on 19/11/2019.
//

#include "Sound.hpp"

Sound::Sound(const std::string &name, const std::string &filePath)
{
    _name = name;
    sf::SoundBuffer buffer;
    buffer.loadFromFile(filePath);
    _sound.setBuffer(buffer);}

Sound::~Sound()
{
}

const sf::Sound &Sound::getSound()
{
    return _sound;
}

const std::string &Sound::getName()
{
    return _name;
}