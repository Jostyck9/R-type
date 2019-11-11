/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** KeyBoard.cpp
*/

#include "KeyBoard.hpp"

using namespace components;

KeyBoard::KeyBoard()
{
}

KeyBoard::~KeyBoard()
{
}

void KeyBoard::setId(const unsigned int &val)
{
    this->_id = val;
}

const unsigned int KeyBoard::getId() const
{
    return (this->_id);
}

const std::type_index KeyBoard::getType() const
{
    return (std::type_index(typeid(KeyBoard)));
}