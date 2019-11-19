/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Sprite.cpp
*/

#include "Sprite.hpp"

ecs::components::Sprite::Sprite()
{
}

ecs::components::Sprite::Sprite(const Sprite &oldSprite)
{
    this->_id = oldSprite.getId();
}

ecs::components::Sprite::~Sprite()
{    
}

void ecs::components::Sprite::setId(const unsigned int &newId)
{
    this->_id = newId;
    return;
}

unsigned int ecs::components::Sprite::getId(void) const
{
    return this->_id;
}

const std::type_index ecs::components::Sprite::getType() const
{
    return (std::type_index(typeid(Sprite)));
}

bool ecs::components::Sprite::operator==(Sprite &other)
{
    if (other.getId() == this->_id)
        return true;
    return false;
}