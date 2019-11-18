/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Sound.cpp
*/

#include "Sound.hpp"

using namespace components;

Sound::Sound()
{
}

Sound::~Sound()
{
}

void Sound::setId(const unsigned int &val)
{
    this->_id = val;
}

unsigned int Sound::getId() const
{
    return (this->_id);
}

const std::type_index Sound::getType() const
{
    return (std::type_index(typeid(Sound)));
}

bool Sound::operator==(Sound const& other) const
{
    if (other.getId() != this->getId())
        return false;
    return true;
}