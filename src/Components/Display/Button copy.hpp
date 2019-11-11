/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Button.hpp
*/

#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <typeindex>
#include "UserInterface.hpp"

namespace components
{
    /**
     * @brief Button describes an attribute that is part of the User Interface. 
     *
     */
    class Button : public UserInterface

    {
    public:
        Button() = default;
        virtual ~Button() = 0;
        void setId(unsigned int id);
        unsigned int getId(void);

    private:
        unsigned int id;
    };
}

#endif //BUTTON_HPP