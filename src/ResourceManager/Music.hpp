//
// Created by romane on 19/11/2019.
//

#ifndef R_TYPE_MUSIC_HPP
#define R_TYPE_MUSIC_HPP

#include <SFML/Audio.hpp>
#include "IAudio.hpp"

class Music : public IAudio {
public:
    Music(const std::string& name, const std::string &filePath);
    ~Music();

    const std::string &getName();

    void play();
    void stop();
    void pause();
    void loop(bool state);

private:
    std::string _name;
    sf::Music _music;
};


#endif //R_TYPE_MUSIC_HPP