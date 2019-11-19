/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Damage.cpp
*/

#include "Damage.hpp"

ecs::components::Damage::Damage()
{
}

ecs::components::Damage::~Damage()
{
}

void ecs::components::Damage::setValue(const float &newValue)
{
    this->_value = newValue;
    return;
}

float ecs::components::Damage::getValue(void) const
{
    return(this->_value);
}

bool ecs::components::Damage::operator==(Damage &other)
{
    if (other.getValue() == this->_value)
        return true;
    return false;
}