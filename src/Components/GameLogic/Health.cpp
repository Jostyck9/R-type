/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Health.cpp
*/

#include "Health.hpp"

components::Health::Health()
{
}

components::Health::~Health()
{
}

void components::Health::setValue(const float &newValue)
{
    this->_value = newValue;
    return;
}

float components::Health::getValue(void) const
{
    return(this->_value);
}

bool components::Health::operator==(Health &other)
{
    if (other.getValue() == this->_value)
        return true;
    return false;
}