/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** GameController.cpp
*/

#include "GameController.hpp"

using namespace components;

GameController::GameController()
{
}

GameController::~GameController()
{
}

void GameController::setId(const unsigned int &val)
{
    this->_id = val;
}

const unsigned int GameController::getId() const
{
    return (this->_id);
}

const std::type_index GameController::getType() const
{
    return (std::type_index(typeid(GameController)));
}