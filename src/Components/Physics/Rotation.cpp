/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Rotation.cpp
*/

#include <cmath>
#include "Rotation.hpp"

using namespace ecs::components;

Rotation::Rotation(const float rotation) : _radAngle((rotation * M_PI) / 180)
{
}

Rotation::Rotation(const Rotation &oldRotation)
{
    this->_radAngle = oldRotation.getRadAngle();
}

Rotation::~Rotation()
{
}

bool Rotation::operator==(Rotation const &other) const
{
    if (this->getRadAngle() != other.getRadAngle())
        return (false);
    return (true);
}


void Rotation::setRadAngle(const float &val)
{
    this->_radAngle = val;
}

float Rotation::getRadAngle() const
{
    return (this->_radAngle);
}

const std::type_index Rotation::getType() const
{
    return (std::type_index(typeid(Rotation)));
}