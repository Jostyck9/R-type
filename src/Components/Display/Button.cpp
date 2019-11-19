/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Button.cpp
*/

#include "Button.hpp"

ecs::components::Button::Button()
{
}

ecs::components::Button::~Button()
{
}


void ecs::components::Button::setId(const unsigned int &newId)
{
    this->_id = newId;
    return;
}

unsigned int ecs::components::Button::getId(void) const
{
    return this->_id;
}

bool ecs::components::Button::operator==(Button &other)
{
    if (other.getId() == this->_id)
        return true;
    return false;
}