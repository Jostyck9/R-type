/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Scale.cpp
*/

#include "Scale.hpp"

ecs::components::Scale::Scale()
{
}

ecs::components::Scale::~Scale()
{
}

void ecs::components::Scale::setValue(const float &newValue)
{
    this->_value = newValue;
    return;
}

float ecs::components::Scale::getValue(void) const
{
    return(this->_value);
}

bool ecs::components::Scale::operator==(Scale &other)
{
    if (other.getValue() == this->_value)
        return true;
    return false;
}