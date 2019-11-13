/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Scale.cpp
*/

#include "Scale.hpp"

components::Scale::Scale()
{
}

components::Scale::~Scale()
{
}

void components::Scale::setValue(const float &newValue)
{
    this->_value = newValue;
    return;
}

float components::Scale::getValue(void) const
{
    return(this->_value);
}

bool components::Scale::operator==(Scale &other)
{
    if (other.getValue() == this->_value)
        return true;
    return false;
}