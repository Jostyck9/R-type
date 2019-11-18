/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Item.cpp
*/

#include "Item.hpp"

components::Item::Item()
{
}

components::Item::~Item()
{
}

void components::Item::setValue(const float &newValue)
{
    this->_value = newValue;
    return;
}

float components::Item::getValue(void) const
{
    return(this->_value);
}

bool components::Item::operator==(Item &other)
{
    if (other.getValue() == this->_value)
        return true;
    return false;
}