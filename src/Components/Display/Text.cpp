/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Text.cpp
*/

#include "Text.hpp"

components::Text::Text()
{
}

components::Text::~Text()
{    
}

void components::Text::setId(const unsigned int &newId)
{
    this->_id = newId;
    return;
}

unsigned int components::Text::getId(void) const
{
    return this->_id;
}

bool components::Text::operator==(Text &other)
{
    if (other.getId() == this->_id)
        return true;
    return false;
}