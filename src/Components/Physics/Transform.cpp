/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Transform.cpp
*/

#include "Transform.hpp"

using namespace components;

Transform::Transform()
{
}

Transform::~Transform()
{
}

void Transform::setValue(const float &val)
{
    this->_value = val;
}

const float Transform::getValue() const
{
    return (this->_value);
}

const std::type_index Transform::getType() const
{
    return (std::type_index(typeid(Transform)));
}