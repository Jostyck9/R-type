/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Power.hpp
*/

#ifndef POWER_HPP
#define POWER_HPP

#include <typeindex>
#include "IGameLogic.hpp"

namespace components
{
    /**
     * @brief Power describes an attribute that stores a numeric value representing Power points. 
     *
     */
    class Power : public IGameLogic

    {
    public:
        Power();
        ~Power();
        void setValue(const float &newValue);
        float getValue(void) const;
        bool operator==(Power &other);
    private:
        float _value;
    };
}

#endif //POWER_HPP