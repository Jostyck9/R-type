/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Sound.hpp
*/

#ifndef SOUND_HPP
#define SOUND_HPP

#include "Sound.hpp"

namespace components
{
    class Sound : public
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
        const unsigned int getId() const;
        /**
         * @brief Get the Type object
         * 
         * @return const std::type_index 
         */
        const std::type_index getType() const override;
    };
}

#endif