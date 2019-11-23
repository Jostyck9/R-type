/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Item.cpp
*/

#include "Item.hpp"

ecs::components::Item::Item()
{
}

ecs::components::Item::Item(const Item &oldItem)
{
    this->_value = oldItem.getValue();
}

ecs::components::Item::~Item()
{
}

void ecs::components::Item::setValue(const float &newValue)
{
    this->_value = newValue;
    return;
}

float ecs::components::Item::getValue(void) const
{
    return(this->_value);
}

const std::type_index ecs::components::Item::getType() const
{
    return (std::type_index(typeid(Item)));
}

bool ecs::components::Item::operator==(Item &other)
{
    if (other.getValue() == this->_value)
        return true;
    return false;
}