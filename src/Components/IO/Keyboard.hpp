/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Keyboard.hpp
*/

#ifndef Keyboard_HPP
#define Keyboard_HPP

#include <map>
#include "Controller.hpp"

namespace ecs::components
{
    /**
     * @brief 
     * 
     */
    class Keyboard
    {
    private:
        unsigned int _id;
        //std::map<> _keyMap;

    public:
        Keyboard();
        Keyboard(const Keyboard &oldKeyboard);
        ~Keyboard();

        /**
         * @brief Set the Id object
         * 
         * @param int 
         */
        void setId(const unsigned int &);

        /**
         * @brief Get the Id object
         * 
         * @return const unsigned int 
         */
        unsigned int getId() const;
        /**
         * @brief Get the Type object
         * 
         * @return const std::type_index 
         */
        const std::type_index getType() const;

        bool operator==(Keyboard const& other) const;
    };
}

#endif