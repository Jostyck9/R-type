/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Power.cpp
*/

#include "Power.hpp"

components::Power::Power()
{
}

components::Power::~Power()
{
}

void components::Power::setValue(const float &newValue)
{
    this->_value = newValue;
    return;
}

float components::Power::getValue(void) const
{
    return(this->_value);
}

bool components::Power::operator==(Power &other)
{
    if (other.getValue() == this->_value)
        return true;
    return false;
}