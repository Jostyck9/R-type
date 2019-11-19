/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Health.cpp
*/

#include "Health.hpp"

ecs::components::Health::Health()
{
}

ecs::components::Health::Health(const Health &oldHealth)
{
    this->_value = oldHealth.getValue();
}

ecs::components::Health::~Health()
{
}

void ecs::components::Health::setValue(const float &newValue)
{
    this->_value = newValue;
    return;
}

float ecs::components::Health::getValue(void) const
{
    return(this->_value);
}

const std::type_index ecs::components::Health::getType() const
{
    return (std::type_index(typeid(Health)));
}

bool ecs::components::Health::operator==(Health &other)
{
    if (other.getValue() == this->_value)
        return true;
    return false;
}