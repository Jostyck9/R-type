/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** PopUp.cpp
*/

#include "PopUp.hpp"

void components::PopUp::setId(const unsigned int &newId)
{
    this->_id = newId;
    return;
}

const unsigned int components::PopUp::getId(void) const
{
    return this->_id;
}