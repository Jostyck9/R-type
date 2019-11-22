//
// Created by romane on 19/11/2019.
//

#include "Music.hpp"
#include "ECSExceptions.hpp"

namespace ecs {

Music::Music(const std::string &name, const std::string &filePath)
{
    _name = name;
    if (!_music.openFromFile(filePath))
        throw ECSExceptions("Error: Could not load music \'" + name + '\'', std::string(__FILE__) + ' ' + std::to_string(__LINE__));
}

Music::~Music()
{

}

void Music::pause()
{
    _music.pause();
}

void Music::stop()
{
    _music.stop();
}

void Music::play()
{
    _music.play();
}

void Music::loop(bool state)
{
    _music.setLoop(state);
}

const std::string &Music::getName()
{
    return _name;
}

}