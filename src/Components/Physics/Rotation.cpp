/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Rotation.cpp
*/

#include "Rotation.hpp"

using namespace components;

Rotation::Rotation()
{
}

Rotation::~Rotation()
{
}

void Rotation::setRadAngle(const float &val)
{
    this->_radAngle = val;
}

const float Rotation::getRadAngle() const
{
    return (this->_radAngle);
}

const std::type_index Rotation::getType() const
{
    return (std::type_index(typeid(Rotation)));
}