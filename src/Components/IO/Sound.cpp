/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Sound.cpp
*/

#include "Sound.hpp"

using namespace ecs::components;

Sound::Sound(std::string nameSound)
{
    _nameSound = nameSound;
}

ecs::components::Sound::Sound(const Sound &oldSound)
{
    this->_nameSound = oldSound.getNameSound();
}

Sound::~Sound()
{
}

const std::string &Sound::getNameSound() const
{
    return _nameSound;
}

const std::type_index Sound::getType() const
{
    return (std::type_index(typeid(Sound)));
}

bool Sound::operator==(const Sound &other) const
{
    return !(other.getNameSound() != this->getNameSound());
}