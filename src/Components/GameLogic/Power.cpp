/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Power.cpp
*/

#include "Power.hpp"

ecs::components::Power::Power()
{
}

ecs::components::Power::~Power()
{
}

void ecs::components::Power::setValue(const float &newValue)
{
    this->_value = newValue;
    return;
}

float ecs::components::Power::getValue(void) const
{
    return(this->_value);
}

const std::type_index ecs::components::Power::getType() const
{
    return (std::type_index(typeid(Power)));
}

bool ecs::components::Power::operator==(Power &other)
{
    if (other.getValue() == this->_value)
        return true;
    return false;
}