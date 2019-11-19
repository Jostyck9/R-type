/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Transform.cpp
*/

#include "Transform.hpp"

using namespace ecs::components;

Transform::Transform()
{
}

Transform::Transform(const Transform &oldTransform)
{
    this->_value = oldTransform.getValue();
}

Transform::~Transform()
{
}

bool Transform::operator==(Transform const &other) const
{
    if (this->getValue() != other.getValue())
        return (false);
    return (true);
}

void Transform::setValue(const float &val)
{
    this->_value = val;
}

float Transform::getValue() const
{
    return (this->_value);
}

const std::type_index Transform::getType() const
{
    return (std::type_index(typeid(Transform)));
}