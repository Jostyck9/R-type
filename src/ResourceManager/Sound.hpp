//
// Created by romane on 19/11/2019.
//

#ifndef R_TYPE_SOUND_HPP
#define R_TYPE_SOUND_HPP

#include <SFML/Audio.hpp>
#include "IAudio.hpp"

namespace ecs {
    class Sound : public IAudio {
    public:
        Sound(const std::string& name, const std::string &filePath);
        ~Sound();

        const std::string &getName();

        void play();
        void stop();
        void pause();
        void loop(bool state);

    private:
        std::string _name;
        sf::Sound _sound;
    };
}

#endif //R_TYPE_SOUND_HPP
