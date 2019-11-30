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

    EnnemiesController::EnnemiesController(const std::string &type) : _shipType(type)
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
