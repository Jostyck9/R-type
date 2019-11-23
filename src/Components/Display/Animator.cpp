/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Animator.cpp
*/

#include "Animator.hpp"

namespace ecs::components {

Animator::Animator()
{
}

Animator::Animator(const Animator &oldAnimator)
{
    this->_id = oldAnimator.getId();
}

Animator::~Animator()
{    
}

void Animator::setId(const unsigned int &newId)
{
    this->_id = newId;
    return;
}

unsigned int Animator::getId(void) const
{
    return this->_id;
}

const std::type_index Animator::getType() const
{
    return (std::type_index(typeid(Animator)));
}

bool Animator::operator==(Animator &other)
{
    if (other.getId() == this->_id)
        return true;
    return false;
}
}