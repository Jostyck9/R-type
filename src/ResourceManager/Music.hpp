//
// Created by romane on 19/11/2019.
//

#ifndef R_TYPE_MUSIC_HPP
#define R_TYPE_MUSIC_HPP

#include <SFML/Audio.hpp>
#include "IAudio.hpp"

namespace ecs {
    /**
     * @brief Music for the game
     * 
     */
    class Music : public IAudio {
    public:
        Music(const std::string& name, const std::string &filePath);
        ~Music();

        /**
         * @brief Get name of the music
         * 
         * @return std::string 
         */
        const std::string &getName() override;

        /**
         * @brief Play the music
         * 
         */
        void play() override;
        
        /**
         * @brief Stop the music
         * 
         */
        void stop() override;
        
        /**
         * @brief Pause the music
         * 
         */
        void pause() override;
        
        /**
         * @brief Loop the music
         * 
         * @param state
         * 
         */
        void loop(bool state) override;

        /**
         * @brief Get state of the music
         *
         */
        IAudio::State getState() override;

        /**
         * @brief Set state of the sound
         *
         */
        void setState(IAudio::State) override;

        /**
         * @brief Get SFML music of the Music
         *
         * @return sf::Music
         */
        sf::Music &getSFMLMusic();

    private:
        std::string _name;
        sf::Music _music;
        State _state;
    };
}

#endif //R_TYPE_MUSIC_HPP