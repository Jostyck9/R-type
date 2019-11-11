/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Collision.cpp
*/

#include "Collision.hpp"

using namespace components;

Collision::Collision()
{
}

Collision::~Collision()
{
}

const bool Collision::operator==(Collision const &other) const
{
    if (this->getX() != other.getX() || this->getY() != other.getY() || this->getHeight() != other.getHeight() || this->getWidth() != other.getWidth())
        return (false);
    return (true);
}

void Collision::setX(const int &val)
{
    this->_x = val;
}

void Collision::setY(const int &val)
{
    this->_y = val;
}

void Collision::setHeight(const float &val)
{
    this->_height = val;
}

void Collision::setWidth(const float &val)
{
    this->_width = val;
}

const int Collision::getX() const
{
    return (this->_x);
}

const int Collision::getY() const
{
    return (this->_y);
}

const float Collision::getHeight() const
{
    return (this->_height);
}
const float Collision::getWidth() const
{
    return (this->_width);
}

const std::type_index Collision::getType() const
{
    return (std::type_index(typeid(Collision)));
}