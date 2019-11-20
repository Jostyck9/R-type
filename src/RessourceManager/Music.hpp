//
// Created by romane on 19/11/2019.
//

#ifndef R_TYPE_MUSIC_HPP
#define R_TYPE_MUSIC_HPP

#include <SFML/Audio.hpp>

class Music {
public:
    Music(const std::string& name, const std::string &filePath);
    ~Music();

    const std::string &getName();
    const sf::Music &getMusic();

private:
    std::string _name;
    sf::Music _music;
};


#endif //R_TYPE_MUSIC_HPP
