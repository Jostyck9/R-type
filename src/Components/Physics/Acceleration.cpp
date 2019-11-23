/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Acceleration.cpp
*/

#include "Acceleration.hpp"

using namespace ecs::components;

Acceleration::Acceleration()
{
}

Acceleration::Acceleration(const Acceleration &oldAcceleration)
{
    this->_value = oldAcceleration.getValue();
}

Acceleration::~Acceleration()
{
}

bool Acceleration::operator==(Acceleration const &other) const
{
    if (this->getValue() != other.getValue())
        return (false);
    return (true);
}

void Acceleration::setValue(const float &val)
{
    this->_value = val;
}

float Acceleration::getValue() const
{
    return (this->_value);
}

const std::type_index Acceleration::getType() const
{
    return (std::type_index(typeid(Acceleration)));
}