/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Level.cpp
*/

#include "Level.hpp"

components::Level::Level()
{
}

components::Level::~Level()
{
}

void components::Level::setValue(const float &newValue)
{
    this->_value = newValue;
    return;
}

const float components::Level::getValue(void) const
{
    return(this->_value);
}

const bool components::Level::operator==(Level &other)
{
    if (other.getValue() == this->_value)
        return true;
    return false;
}