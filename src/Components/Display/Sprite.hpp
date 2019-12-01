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
        Sprite(const std::string &name, Rect &rect, bool isVisible);
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
        /**
         * @brief Get the Name object
         * 
         * @return std::string 
         */
        std::string getName() const;
        /**
         * @brief Get the Rect object
         * 
         * @return const ecs::Rect& 
         */
        const ecs::Rect &getRect() const;    
        /**
         * @brief Set the Rect object
         * 
         * @param rect 
         */
        void setRect(const Rect &rect);
        /**
         * @brief Get the Is Visible object
         * 
         * @return true 
         * @return false 
         */
        const bool &getIsVisible() const;
        /**
         * @brief Set the Is Visible object
         * 
         * @param state 
         */
        void setIsVisible(bool &state);
        
    private:
       unsigned int _id;
       std::string _name;
       ecs::Rect _rect;
       bool _isVisible; /*!<show the image or not */

    //    std::pair<int, int> _size; /*!<contains maximal width and length of the sprite */
    };
}

#endif //SPRITE_HPP