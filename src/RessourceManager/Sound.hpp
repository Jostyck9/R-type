//
// Created by romane on 19/11/2019.
//

#ifndef R_TYPE_SOUND_HPP
#define R_TYPE_SOUND_HPP

#include <SFML/Audio.hpp>

class Sound {
public:
    Sound(const std::string& name, const std::string &filePath);
    ~Sound();

    const std::string &getName();
    const sf::Sound &getSound();

private:
    std::string _name;
    sf::Sound _sound;
};


#endif //R_TYPE_SOUND_HPP
