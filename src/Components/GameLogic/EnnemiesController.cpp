/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** EnnemiesController.cpp
*/

#include <iostream>
#include "EnnemiesController.hpp"

using namespace ecs::components;
EnnemiesController::EnnemiesController() : _shipType("Basic"), _interval(0)
{
    _timer.start();
}

EnnemiesController::EnnemiesController(const std::string &type) : _shipType(type), _interval(1)
{
    _timer.start();
    if (_shipType == "Wave")
        _interval = 3;
}

EnnemiesController::EnnemiesController(const EnnemiesController &oldEnnemiesController)
{
    _shipType = oldEnnemiesController.getShipType();
}

const std::type_index EnnemiesController::getType() const
{
    return (std::type_index(typeid(EnnemiesController)));
}

std::string EnnemiesController::getShipType(void) const
{
    return this->_shipType;
}

void EnnemiesController::setShipType(const std::string &type)
{
    _shipType = type;
}

bool EnnemiesController::operator==(EnnemiesController &other)
{
    return true;
}

double EnnemiesController::getInterval() const
{
    return _interval;
}

void EnnemiesController::setInterval(double intervalSecond)
{
    _interval = intervalSecond;
}

Timer &EnnemiesController::getTimer()
{
    return _timer;
}