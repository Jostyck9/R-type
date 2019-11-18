/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** PopUp.cpp
*/

#include "PopUp.hpp"

components::PopUp::PopUp()
{
}

components::PopUp::~PopUp()
{    
}

void components::PopUp::setId(const unsigned int &newId)
{
    this->_id = newId;
    return;
}

unsigned int components::PopUp::getId(void) const
{
    return this->_id;
}

bool components::PopUp::operator==(PopUp &other)
{
    if (other.getId() == this->_id)
        return true;
    return false;
}