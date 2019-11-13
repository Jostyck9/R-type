/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Sprite.cpp
*/

#include "Sprite.hpp"

components::Sprite::Sprite()
{
}

components::Sprite::~Sprite()
{    
}

void components::Sprite::setId(const unsigned int &newId)
{
    this->_id = newId;
    return;
}

unsigned int components::Sprite::getId(void) const
{
    return this->_id;
}

bool components::Sprite::operator==(Sprite &other)
{
    if (other.getId() == this->_id)
        return true;
    return false;
}