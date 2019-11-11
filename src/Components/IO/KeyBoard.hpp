/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** KeyBoard.hpp
*/

#ifndef KEYBOARD_HPP
#define KEYBOARD_HPP

#include <map>
#include "Controller.hpp"

namespace components
{
    /**
     * @brief 
     * 
     */
    class KeyBoard
    {
    private:
        unsigned int _id;
        //std::map<> _keyMap;

    public:
        KeyBoard();
        ~KeyBoard();

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
        const unsigned int getId() const;
        /**
         * @brief Get the Type object
         * 
         * @return const std::type_index 
         */
        const std::type_index getType() const override;

        const bool operator==(KeyBoard const& other) const;
    };
}

#endif