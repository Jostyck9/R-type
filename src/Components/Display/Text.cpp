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

const unsigned int components::Text::getId(void) const
{
    return this->_id;
}