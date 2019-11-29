/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Entity.cpp
*/

#include <iostream>
#include "Entity.hpp"

using namespace ecs::entities;

Entity::Entity(option gameId) : _id(0), _gameId(gameId)
{
    static size_t id = 0;
    static size_t allGameId = AUTOID + 1;

    _id = id++;
    if (gameId == AUTOID) {
        _gameId = allGameId++;
    }
}

Entity::~Entity()
{
}

size_t Entity::getID() const
{
    return _id;
}

size_t Entity::getInGameID() const
{
    return _gameId;
}