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

const float components::Power::getValue(void) const
{
    return(this->_value);
}