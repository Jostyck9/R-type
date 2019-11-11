/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Power.hpp
*/

#ifndef POWER_HPP
#define POWER_HPP

#include <typeindex>
#include "UserInterface.hpp"

namespace components
{
    /**
     * @brief Power describes an attribute that stores a numeric value representing Power points. 
     *
     */
    class Power : public UserInterface

    {
    public:
        Power();
        ~Power();
        void setValue(const float &newValue);
        const float getValue(void) const;

    private:
        float _value;
    };
}

#endif //POWER_HPP