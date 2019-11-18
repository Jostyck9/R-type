/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Animator.cpp
*/

#include "Animator.hpp"

components::Animator::Animator()
{
}

components::Animator::~Animator()
{    
}

void components::Animator::setId(const unsigned int &newId)
{
    this->_id = newId;
    return;
}

unsigned int components::Animator::getId(void) const
{
    return this->_id;
}

bool components::Animator::operator==(Animator &other)
{
    if (other.getId() == this->_id)
        return true;
    return false;
}