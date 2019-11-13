/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Button.cpp
*/

#include "Button.hpp"

components::Button::Button()
{
}

components::Button::~Button()
{    
}


void components::Button::setId(const unsigned int &newId)
{
    this->_id = newId;
    return;
}

const unsigned int components::Button::getId(void) const
{
    return this->_id;
}

const bool components::Button::operator==(Button &other)
{
    if (other.getId() == this->_id)
        return true;
    return false;
}