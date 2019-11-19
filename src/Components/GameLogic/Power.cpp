/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Power.cpp
*/

#include "Power.hpp"

ecs::components::Power::Power()
{
}

ecs::components::Power::~Power()
{
}

void ecs::components::Power::setValue(const float &newValue)
{
    this->_value = newValue;
    return;
}

float ecs::components::Power::getValue(void) const
{
    return(this->_value);
}

bool ecs::components::Power::operator==(Power &other)
{
    if (other.getValue() == this->_value)
        return true;
    return false;
}