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

    private:
        std::string _name;
        sf::Sound _sound;
    };
}

#endif //R_TYPE_SOUND_HPP
