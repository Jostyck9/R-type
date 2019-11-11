/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Animator.cpp
*/

#include "Animator.hpp"

void components::Animator::setId(unsigned int newId)
{
    this->_id = newId;
    return;
}

const unsigned int components::Animator::getId(void) const
{
    return this->_id;
}