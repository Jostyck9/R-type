/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Damage.cpp
*/

#include "Damage.hpp"

ecs::components::Damage::Damage() : _value(0)
{
}

ecs::components::Damage::Damage(int dmg) : _value(dmg)
{
}

ecs::components::Damage::Damage(const Damage &oldDamage)
{
    this->_value = oldDamage.getValue();
}

ecs::components::Damage::~Damage()
{
}

void ecs::components::Damage::setValue(const float &newValue)
{
    this->_value = newValue;
    return;
}

float ecs::components::Damage::getValue(void) const
{
    return(this->_value);
}

const std::type_index ecs::components::Damage::getType() const
{
    return (std::type_index(typeid(Damage)));
}

bool ecs::components::Damage::operator==(Damage &other)
{
    if (other.getValue() == this->_value)
        return true;
    return false;
}