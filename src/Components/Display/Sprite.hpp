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

namespace ecs::components
{
    /**
     * @brief Sprite describes an attribute that contains an image id. 
     *
     */
    class Sprite : public IDisplay

    {
    public:
        Sprite();
        ~Sprite();
         /**
         * @brief Set new value to the component id
         * 
         * @param newId 
         */
        void setId(const unsigned int &newId);
         /**
         * @brief return the component id
         * 
         */
        unsigned int getId(void) const;
        /**
         * @brief Get the Type object
         * 
         * @return const std::type_index 
         */
        const std::type_index getType() const;
        bool operator==(Sprite &other);
    private:
       unsigned int _id;
    };
}

#endif //SPRITE_HPP