/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Level.cpp
*/

#include "Level.hpp"

ecs::components::Level::Level()
{
}

ecs::components::Level::Level(const Level &oldLevel)
{
    this->_value = oldLevel.getValue();
}

ecs::components::Level::~Level()
{
}

void ecs::components::Level::setValue(const float &newValue)
{
    this->_value = newValue;
    return;
}

float ecs::components::Level::getValue(void) const
{
    return(this->_value);
}

const std::type_index ecs::components::Level::getType() const
{
    return (std::type_index(typeid(Level)));
}

bool ecs::components::Level::operator==(Level &other)
{
    if (other.getValue() == this->_value)
        return true;
    return false;
}