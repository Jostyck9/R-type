/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Sprite.hpp
*/

#ifndef SPRITE_HPP
#define SPRITE_HPP

#include <typeindex>
#include "IDisplay.hpp"

namespace components
{
    /**
     * @brief Sprite describes an attribute that contains an image id. 
     *
     */
    class Sprite : public IDisplay

    {
    public:
        Sprite() = default;
        virtual ~Sprite() = 0;
        void setId(const unsigned int newId);
        const unsigned int getId(void) const;

    private:
       unsigned int _id;
    };
}

#endif //SPRITE_HPP