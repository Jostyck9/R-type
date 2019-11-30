/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** StaticText.cpp
*/

#include <typeindex>
#include "StaticText.hpp"

ecs::components::StaticText::StaticText() : _str("null")
{
}

ecs::components::StaticText::StaticText(std::string &str) : _str(str)
{
}

ecs::components::StaticText::~StaticText()
{
}

const std::type_index ecs::components::StaticText::getType() const
{
    return (std::type_index(typeid(StaticText)));
}