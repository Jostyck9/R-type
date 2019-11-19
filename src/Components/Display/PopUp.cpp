/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** PopUp.cpp
*/

#include "PopUp.hpp"

ecs::components::PopUp::PopUp()
{
}

ecs::components::PopUp::~PopUp()
{    
}

void ecs::components::PopUp::setId(const unsigned int &newId)
{
    this->_id = newId;
    return;
}

unsigned int ecs::components::PopUp::getId(void) const
{
    return this->_id;
}

const std::type_index ecs::components::PopUp::getType() const
{
    return (std::type_index(typeid(PopUp)));
}

bool ecs::components::PopUp::operator==(PopUp &other)
{
    if (other.getId() == this->_id)
        return true;
    return false;
}