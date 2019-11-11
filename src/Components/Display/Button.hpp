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
     * @brief Button describes an attribute that is button. 
     *
     */
    class Button : public UserInterface

    {
    public:
        Button();
        ~Button();
        void setId(const unsigned int &newId);
        const unsigned int getId(void) const;

    private:
        unsigned int _id;
    };
}

#endif //BUTTON_HPP