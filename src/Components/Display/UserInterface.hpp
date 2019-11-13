/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** UserInterface.hpp
*/

#ifndef USERINTERFACE_HPP
#define USERINTERFACE_HPP

#include <typeindex>
#include "IDisplay.hpp"

namespace components
{
    /**
     * @brief UserInterface describes an attribute that is part of the User Interface. 
     *
     */
    class UserInterface : public IDisplay

    {
    public:
        UserInterface();
        ~UserInterface();
    };
}

#endif //UserInterface_HPP