/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** EnemiesController.cpp
*/

#include <iostream>
#include "EnemiesController.hpp"

using namespace ecs::components;
EnemiesController::EnemiesController() : _shipType("Basic"), _interval(0)
{
    _timer.start();
}

EnemiesController::EnemiesController(const std::string &type) : _shipType(type), _interval(1)
{
    _timer.start();
    if (_shipType == "Wave")
        _interval = 3;
}

EnemiesController::EnemiesController(const EnemiesController &oldEnemiesController)
{
    _shipType = oldEnemiesController.getShipType();
}

const std::type_index EnemiesController::getType() const
{
    return (std::type_index(typeid(EnemiesController)));
}

std::string EnemiesController::getShipType(void) const
{
    return this->_shipType;
}

void EnemiesController::setShipType(const std::string &type)
{
    _shipType = type;
}

bool EnemiesController::operator==(EnemiesController &other)
{
    return true;
}

double EnemiesController::getInterval() const
{
    return _interval;
}

void EnemiesController::setInterval(double intervalSecond)
{
    _interval = intervalSecond;
}

Timer &EnemiesController::getTimer()
{
    return _timer;
}
