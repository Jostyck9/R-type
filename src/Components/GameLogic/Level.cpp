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