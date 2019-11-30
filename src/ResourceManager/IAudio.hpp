//
// Created by romane on 19/11/2019.
//

#ifndef R_TYPE_IAUDIO_HPP
#define R_TYPE_IAUDIO_HPP

namespace ecs {
    /**
     * @brief Audio for the game
     * 
     */
    class IAudio {
    public:
        enum State {
            PLAYING,
            PAUSED,
            STOP
        };

        /**
         * @brief Get name of the music
         * 
         * @return std::string 
         */
        virtual const std::string &getName() = 0;
        
        /**
         * @brief Play the audio
         * 
         */
        virtual void play() = 0;
        
        /**
         * @brief Stop the audio
         * 
         */
        virtual void stop() = 0;
        
        /**
         * @brief Pause the audio
         * 
         */
        virtual void pause() = 0;
        
        /**
         * @brief Loop the audio
         * 
         */
        virtual void loop(bool state) = 0;

        /**
         * @brief Get state of the audio
         *
         */
        virtual State getState() = 0;

        /**
         * @brief Set state oh the audio
         *
         */
        virtual void setState(State) = 0;
    };
}

#endif //R_TYPE_IAUDIO_HPP