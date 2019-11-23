/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** GameController.cpp
*/

#include "GameController.hpp"

using namespace ecs::components;

GameController::GameController()
{
}

ecs::components::GameController::GameController(const GameController &oldGameController)
{
    this->_id = oldGameController.getId();
}

GameController::~GameController()
{
}

void GameController::setId(const unsigned int &val)
{
    this->_id = val;
}

unsigned int GameController::getId() const
{
    return (this->_id);
}

const std::type_index GameController::getType() const
{
    return (std::type_index(typeid(GameController)));
}

bool GameController::operator==(GameController const& other) const
{
    if (other.getId() != this->getId())
        return false;
    return true;
}