/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** SystemResponse.cpp
*/

#include "SystemResponse.hpp"

namespace ecs::system
{

SystemResponse::SystemResponse(CMD action, std::string parameters) : _action(action), _parameters(parameters)
{
}

SystemResponse::~SystemResponse()
{
}

const SystemResponse::CMD &SystemResponse::getAction() const
{
    return _action;
}

const std::string &SystemResponse::getParameters() const
{
    return _parameters;
}

void SystemResponse::setAction(const SystemResponse::CMD &action)
{
    _action = action;
}

void SystemResponse::setParameters(const std::string &parameters)
{
    _parameters = parameters;
}

} // namespace ecs