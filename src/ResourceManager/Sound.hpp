//
// Created by romane on 19/11/2019.
//

#ifndef R_TYPE_SOUND_HPP
#define R_TYPE_SOUND_HPP

#include <SFML/Audio.hpp>
#include "IAudio.hpp"

namespace ecs {
    /**
     * @brief Sound for the game
     * 
     */ 
    class Sound : public IAudio {
    public:
        Sound(const std::string& name, const std::string &filePath);
        ~Sound();

        /**
         * @brief Get name of the sound
         * 
         * @return std::string
         */
        const std::string &getName() override;

        /**
         * @brief Play the sound
         * 
         */
        void play() override;
        
        /**
         * @brief Stop the sound
         * 
         */
        void stop() override;
        
        /**
         * @brief Pause the sound
         * 
         */
        void pause() override;
        
        /**
         * @brief Loop the sound
         * 
         * @param state
         * 
         */
        void loop(bool state) override;

        /**
         * @brief Get state of the sound
         *
         */
        IAudio::State getState() override;

        /**
         * @brief Set state of the sound
         *
         */
        void setState(IAudio::State) override;

        /**
         * @brief Get SFML sound of the Sound
         *
         * @return sf::Sound
         */
        sf::Sound &getSFMLSound();


    private:
        std::string _name;
        sf::Sound _sound;
        State _state;
        sf::SoundBuffer _buffer;
    };
}

#endif //R_TYPE_SOUND_HPP
