/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Sound.hpp
*/

#ifndef SOUND_HPP
#define SOUND_HPP

#include <string>
#include "Output.hpp"

namespace ecs::components
{
    class Sound : public Output
    {
    private:
        unsigned int _id;
    public:
        Sound(std::string nameSound);
        Sound(const Sound &oldSound);
        ~Sound();

        /**
         * @brief Get the name of the sound
         *
         * @return const std::string &
         */
        const std::string &getNameSound() const;
        /**
         * @brief Get the Type object
         * 
         * @return const std::type_index 
         */
        const std::type_index getType() const;

        bool operator==(const Sound &other) const;

    private:
        std::string _nameSound;
    };
}

#endif