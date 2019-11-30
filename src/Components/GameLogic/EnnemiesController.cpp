/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** EnnemiesController.cpp
*/

#include "EnnemiesController.hpp"
using namespace ecs::components;
	EnnemiesController::EnnemiesController() : _shipType("basic")
    {
    }

    EnnemiesController::EnnemiesController(std::string &type) : _shipType(type)
    {
    }

    EnnemiesController::EnnemiesController(const EnnemiesController &oldEnnemiesController)
    {
        _shipType = oldEnnemiesController.getShipType();
    }

    const std::type_index EnnemiesController::getType() const
    {
        return (std::type_index(typeid(EnnemiesController)));
    }

    const std::string EnnemiesController::getShipType() const
    {
        return _shipType;
    }

    void EnnemiesController::setShipType(std::string & type)
    {
        _shipType = type;
    }

    bool EnnemiesController::operator==(EnnemiesController &other)
    {
        return true;
    }
