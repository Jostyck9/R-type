/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Text.cpp
*/

#include "Text.hpp"

ecs::components::Text::Text()
{
}

ecs::components::Text::Text(const Text &oldText)
{
    this->_id = oldText.getId();
}

ecs::components::Text::~Text()
{    
}

void ecs::components::Text::setId(const unsigned int &newId)
{
    this->_id = newId;
    return;
}

unsigned int ecs::components::Text::getId(void) const
{
    return this->_id;
}

const std::type_index ecs::components::Text::getType() const
{
    return (std::type_index(typeid(Text)));
}

bool ecs::components::Text::operator==(Text &other)
{
    if (other.getId() == this->_id)
        return true;
    return false;
}