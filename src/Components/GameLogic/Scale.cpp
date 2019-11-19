/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Scale.cpp
*/

#include "Scale.hpp"

ecs::components::Scale::Scale()
{
}

ecs::components::Scale::Scale(const Scale &oldScale)
{
    this->_value = oldScale.getValue();
}

ecs::components::Scale::~Scale()
{
}

void ecs::components::Scale::setValue(const float &newValue)
{
    this->_value = newValue;
    return;
}

float ecs::components::Scale::getValue(void) const
{
    return(this->_value);
}

const std::type_index ecs::components::Scale::getType() const
{
    return (std::type_index(typeid(Scale)));
}

bool ecs::components::Scale::operator==(Scale &other)
{
    if (other.getValue() == this->_value)
        return true;
    return false;
}