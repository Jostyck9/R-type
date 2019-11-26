/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Velocity.cpp
*/

#include <utility>
#include "Velocity.hpp"

using namespace ecs::components;

Velocity::Velocity(float x, float y) : _velocityX(x), _velocityY(y)
{
}

Velocity::Velocity(const Velocity &oldVelocity)
{
    this->_velocityX = oldVelocity.getVelocityX();
    this->_velocityY = oldVelocity.getVelocityY();
}

Velocity::~Velocity()
{
}

void Velocity::setVelocityX(const float &x)
{
    _velocityX = x;
}

float Velocity::getVelocityX() const
{
    return _velocityX;
}

void Velocity::setVelocityY(const float &y)
{
    _velocityY = y;
}

float Velocity::getVelocityY() const
{
    return _velocityY;
}

void Velocity::setVelocity(const float &x, const float &y)
{
    _velocityX = x;
    _velocityY = y;
}

const std::pair<float, float> Velocity::getVelocity() const
{
    return std::make_pair(_velocityX, _velocityY);
}

const std::type_index Velocity::getType() const
{
    return (std::type_index(typeid(Velocity)));
}