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

    private:
        std::string _name;
        sf::Music _music;
    };
}

#endif //R_TYPE_MUSIC_HPP