/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Image.cpp
*/

#include "Image.hpp"

ecs::components::Image::Image()
{
}

ecs::components::Image::Image(const Image &oldImage)
{
    this->_id = oldImage.getId();
}

ecs::components::Image::~Image()
{    
}

void ecs::components::Image::setId(const unsigned int &newId)
{
    this->_id = newId;
    return;
}

unsigned int ecs::components::Image::getId(void) const
{
    return this->_id;
}

const std::type_index ecs::components::Image::getType() const
{
    return (std::type_index(typeid(Image)));
}

bool ecs::components::Image::operator==(Image &other)
{
    if (other.getId() == this->_id)
        return true;
    return false;
}