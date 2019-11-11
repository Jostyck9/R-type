/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Sprite.cpp
*/

#include "Sprite.hpp"

void components::Sprite::setId(const unsigned int &newId)
{
    this->_id = newId;
    return;
}

const unsigned int components::Sprite::getId(void) const
{
    return this->_id;
}