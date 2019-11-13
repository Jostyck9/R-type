/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Image.cpp
*/

#include "Image.hpp"

components::Image::Image()
{
}

components::Image::~Image()
{    
}

void components::Image::setId(const unsigned int &newId)
{
    this->_id = newId;
    return;
}

const unsigned int components::Image::getId(void) const
{
    return this->_id;
}

const bool components::Image::operator==(Image &other)
{
    if (other.getId() == this->_id)
        return true;
    return false;
}