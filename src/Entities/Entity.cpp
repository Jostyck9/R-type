/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Entity.cpp
*/

#include <iostream>
#include "Entity.hpp"

using namespace entities;

Entity::Entity() : _id(0)
{
    static size_t id = 0;

    _id = id++;
}

Entity::~Entity()
{
}

size_t Entity::getID() const
{
    return _id;
}