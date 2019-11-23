//
// Created by romane on 19/11/2019.
//

#include "Sound.hpp"
#include "ECSExceptions.hpp"

namespace ecs {

Sound::Sound(const std::string &name, const std::string &filePath)
{
    _name = name;
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile(filePath))
        throw ECSExceptions("Error: Could not load sound \'" + name + '\'', std::string(__FILE__) + ' ' + std::to_string(__LINE__));
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