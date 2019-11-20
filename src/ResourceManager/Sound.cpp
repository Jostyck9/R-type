//
// Created by romane on 19/11/2019.
//

#include "Sound.hpp"

namespace ecs {

Sound::Sound(const std::string &name, const std::string &filePath)
{
    _name = name;
    sf::SoundBuffer buffer;
    buffer.loadFromFile(filePath);
    _sound.setBuffer(buffer);}

Sound::~Sound()
{
}

void Sound::pause()
{
    _sound.pause();
}

void Sound::stop()
{
    _sound.stop();
}

void Sound::play()
{
    _sound.play();
}

void Sound::loop(bool state)
{
    _sound.setLoop(state);
}

const std::string &Sound::getName()
{
    return _name;
}

}