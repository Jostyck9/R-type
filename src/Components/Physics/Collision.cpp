/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Collision.cpp
*/

#include <string>
#include "Collision.hpp"

using namespace ecs::components;

Collision::Collision(bool triggered, float x, float y, float width, float height, const std::string &tag) : _x(x), _y(y), _height(height), _width(width), _triggered(triggered), _collide(false), _tag(tag)
{
}

Collision::Collision(const Collision &oldCollision)
{
    this->_height = oldCollision.getHeight();
    this->_width = oldCollision.getWidth();
    this->_x = oldCollision.getX();
    this->_y = oldCollision.getY();
}

Collision::~Collision()
{
}

bool Collision::operator==(Collision const &other) const
{
    if (this->getX() != other.getX() || this->getY() != other.getY() || this->getHeight() != other.getHeight() || this->getWidth() != other.getWidth())
        return (false);
    return (true);
}

bool Collision::isColliding() const
{
    return _collide;
}

void Collision::setCollinding(bool isColliding)
{
    _collide = isColliding;
}

bool Collision::isTriggered() const
{
    return _triggered;
}

void Collision::setTriggered(bool isTriggered)
{
    _triggered = isTriggered;
}

const std::map<size_t, std::string> &Collision::getCollidedTags() const
{
    return _encounteredTag;
}

void Collision::clearTags()
{
    _encounteredTag.clear();
}

void Collision::addTag(const size_t idEntity, const std::string &tag)
{
    _encounteredTag[idEntity] = tag;
}

const std::string &Collision::getTag() const
{
    return _tag;
}

void Collision::setTag(const std::string &tag)
{
    _tag = tag;
}

void Collision::setX(const float &val)
{
    this->_x = val;
}

void Collision::setY(const float &val)
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

float Collision::getX() const
{
    return (this->_x);
}

float Collision::getY() const
{
    return (this->_y);
}

float Collision::getHeight() const
{
    return (this->_height);
}

float Collision::getWidth() const
{
    return (this->_width);
}

const std::type_index Collision::getType() const
{
    return (std::type_index(typeid(Collision)));
}