/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Velocity.cpp
*/

#include "Velocity.hpp"

using namespace components;

Velocity::Velocity()
{
}

Velocity::~Velocity()
{
}

bool Velocity::operator==(Velocity const &other) const
{
    if (this->getValue() != other.getValue())
        return (false);
    return (true);
}

void Velocity::setValue(const float &val)
{
    this->_value = val;
}

float Velocity::getValue() const
{
    return (this->_value);
}

const std::type_index Velocity::getType() const
{
    return (std::type_index(typeid(Velocity)));
}