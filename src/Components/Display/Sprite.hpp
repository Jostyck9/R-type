/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Sprite.hpp
*/

#ifndef SPRITE_HPP
#define SPRITE_HPP

#include <string>
#include <typeindex>
#include "Rect.hpp"
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
        Sprite(const std::string &name, Rect &rect);
        Sprite(const Sprite &oldSprite);
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
        std::string getName() const;
        ecs::Rect getRect() const;
        
    private:
       unsigned int _id;
       std::string _name;
       ecs::Rect _rect;
    };
}

#endif //SPRITE_HPP