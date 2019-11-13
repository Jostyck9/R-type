/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Damage.cpp
*/

#include "Damage.hpp"

components::Damage::Damage()
{
}

components::Damage::~Damage()
{
}

void components::Damage::setValue(const float &newValue)
{
    this->_value = newValue;
    return;
}

const float components::Damage::getValue(void) const
{
    return(this->_value);
}

const bool components::Damage::operator==(Damage &other)
{
    if (other.getValue() == this->_value)
        return true;
    return false;
}