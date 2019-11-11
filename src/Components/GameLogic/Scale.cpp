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

const float components::Scale::getValue(void) const
{
    return(this->_value);
}