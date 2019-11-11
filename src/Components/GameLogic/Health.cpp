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

const float components::Health::getValue(void) const
{
    return(this->_value);
}