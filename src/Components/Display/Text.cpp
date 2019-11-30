/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Text.cpp
*/

#include "Color.hpp"
#include "Text.hpp"

ecs::components::Text::Text() : _string("null") ,_size(15), _color(ecs::Color::WHITE)
{
}

ecs::components::Text::Text(const std::string &str, int size) : _string(str) ,_size(size), _color(ecs::Color::WHITE)
{
}

ecs::components::Text::Text(const Text &oldText)
{
    this->_id = oldText.getId();
    this->_size = oldText.getSize();
    this->_string = oldText.getStr();
    this->_color = oldText.getColor();
}

ecs::components::Text::~Text()
{    
}

void ecs::components::Text::setId(const unsigned int &newId)
{
    this->_id = newId;
    return;
}

unsigned int ecs::components::Text::getId(void) const
{
    return this->_id;
}

void ecs::components::Text::setStr(const std::string &newstr)
{
    this->_string = newstr;
}

std::string ecs::components::Text::getStr(void) const
{
    return this->_string;
}

const std::type_index ecs::components::Text::getType() const
{
    return (std::type_index(typeid(Text)));
}

void ecs::components::Text::setSize(const int &newSize)
{
    this->_size = newSize;
}

int ecs::components::Text::getSize(void) const
{
    return this->_size;
}

void ecs::components::Text::setColor(const ecs::Color &newColor)
{
    this->_color = newColor;

}

ecs::Color ecs::components::Text::getColor(void) const
{
    return this->_color;
}


bool ecs::components::Text::operator==(Text &other)
{
    return other.getId() == this->_id;
}