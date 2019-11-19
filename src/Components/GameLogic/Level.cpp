/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Level.cpp
*/

#include "Level.hpp"

ecs::components::Level::Level()
{
}

ecs::components::Level::~Level()
{
}

void ecs::components::Level::setValue(const float &newValue)
{
    this->_value = newValue;
    return;
}

float ecs::components::Level::getValue(void) const
{
    return(this->_value);
}

bool ecs::components::Level::operator==(Level &other)
{
    if (other.getValue() == this->_value)
        return true;
    return false;
}