/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Text.cpp
*/

#include "Text.hpp"

void components::Text::setId(unsigned int newId)
{
    this->_id = newId;
    return;
}

const unsigned int components::Text::getId(void) const
{
    return this->_id;
}