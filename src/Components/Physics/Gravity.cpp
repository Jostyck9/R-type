/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Gravity.cpp
*/

#include "Gravity.hpp"

using namespace components;

Gravity::Gravity()
{
}

Gravity::~Gravity()
{
}

void Gravity::setValue(const float &val)
{
    this->_value = val;
}

const float Gravity::getValue() const
{
    return (this->_value);
}

const std::type_index Gravity::getType() const
{
    return (std::type_index(typeid(Gravity)));
}