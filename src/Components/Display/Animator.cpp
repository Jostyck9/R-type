/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Animator.cpp
*/

#include "Animator.hpp"

ecs::components::Animator::Animator()
{
}

ecs::components::Animator::~Animator()
{    
}

void ecs::components::Animator::setId(const unsigned int &newId)
{
    this->_id = newId;
    return;
}

unsigned int ecs::components::Animator::getId(void) const
{
    return this->_id;
}

const std::type_index ecs::components::Animator::getType() const
{
    return (std::type_index(typeid(Animator)));
}

bool ecs::components::Animator::operator==(Animator &other)
{
    if (other.getId() == this->_id)
        return true;
    return false;
}