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

void components::Item::setValue(const unsigned int &newValue)
{
    this->_value = newValue;
    return;
}

const unsigned int components::Item::getValue(void) const
{
    return(this->_value);
}