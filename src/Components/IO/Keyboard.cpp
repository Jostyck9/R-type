/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Keyboard.cpp
*/

#include "Keyboard.hpp"

using namespace ecs::components;

Keyboard::Keyboard()
{
}

ecs::components::Keyboard::Keyboard(const Keyboard &oldKeyboard)
{
    this->_id = oldKeyboard.getId();
}

Keyboard::~Keyboard()
{
}

void Keyboard::setId(const unsigned int &val)
{
    this->_id = val;
}

unsigned int Keyboard::getId() const
{
    return (this->_id);
}

const std::type_index Keyboard::getType() const
{
    return (std::type_index(typeid(Keyboard)));
}

bool Keyboard::operator==(Keyboard const& other) const
{
    if (other.getId() != this->getId())
        return false;
    return true;
}