/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Button.cpp
*/

#include "Button.hpp"

void components::Button::setId(unsigned int newId)
{
    this->_id = newId;
    return;
}

const unsigned int components::Button::getId(void) const
{
    return this->_id;
}