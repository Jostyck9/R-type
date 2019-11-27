/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Rect.cpp
*/

#include "Rect.hpp"

using namespace ecs;

Rect::Rect(int width, int height, int posX, int posY) : _width(width), _height(height), _posX(posX), _posY(posY)
{
}

Rect::Rect(const Rect &oldRect)
{
    _width = oldRect.getWidth();
    _height = oldRect.getHeight();
    _posX = oldRect.getPosX();
    _posY = oldRect.getPosY();
}

Rect::~Rect()
{
}

int Rect::getWidth()const
{
    return _width;
}

int Rect::getHeight()const
{
    return _height;
}

int Rect::getPosX()const
{
    return _posX;
}

int Rect::getPosY()const
{
    return _posY;
}

bool ecs::Rect::operator==(const Rect &other) const
{
    if (other.getHeight() != this->_height)
        return false;
    if (other.getWidth() != this->_width)
        return false;
    if (other.getPosY() != this->_posY)
        return false;
    if (other.getPosX() != this->_posX)
        return false;
    return true;
}