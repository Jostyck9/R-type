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

ecs::components::Sprite::Sprite(const std::string &name, const int &height, const int &width) : _name(name), _rect(height, width)
{
}

ecs::components::Sprite::Sprite(const Sprite &oldSprite)
{
    this->_id = oldSprite.getId();
    this->_name = oldSprite.getName();
    this->_rect = oldSprite.getRect();
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

std::string ecs::components::Sprite::getName() const
{
    return this->_name;
}

std::pair<int, int> ecs::components::Sprite::getRect() const
{
    return this->_rect;
}

bool ecs::components::Sprite::operator==(Sprite &other)
{
    if (other.getId() == this->_id)
        return true;
    if (other.getName() == this->_name)
        return true;
    if (other.getRect() == this->_rect)
        return true;
    return false;
}
