/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Sound.hpp
*/

#ifndef SOUND_HPP
#define SOUND_HPP

#include "Output.hpp"

namespace ecs::components
{
    class Sound : public Output
    {
    private:
        unsigned int _id;
    public:
        Sound();
        ~Sound();

        /**
         * @brief Set the Id object
         * 
         * @param int 
         */
        void setId(const unsigned int &);

        /**
         * @brief Get the Id object
         * 
         * @return unsigned int 
         */
        unsigned int getId() const;
        /**
         * @brief Get the Type object
         * 
         * @return const std::type_index 
         */
        const std::type_index getType() const;

        bool operator==(Sound const& other) const;
    };
}

#endif