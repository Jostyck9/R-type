//
// Created by romane on 19/11/2019.
//

#include "Music.hpp"

Music::Music(const std::string &name, const std::string &filePath)
{
    _name = name;
    _music.openFromFile(filePath);
}

Music::~Music()
{
}

const sf::Music &Music::getMusic()
{
    return _music;
}

const std::string &Music::getName()
{
    return _name;
}