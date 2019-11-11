/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Image.cpp
*/

#include "Image.hpp"

void components::Image::setId(unsigned int newId)
{
    this->_id = newId;
    return;
}

const unsigned int components::Image::getId(void) const
{
    return this->_id;
}