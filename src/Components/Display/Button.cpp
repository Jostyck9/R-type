/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Button.cpp
*/

#include "Button.hpp"

ecs::components::Button::Button(bool isSelected, ecs::system::SystemResponse::CMD cmd, const std::string &parameter)
{
    _isSelected = isSelected;
    _cmd = cmd;
    _parameter = parameter;
}

ecs::components::Button::Button(const Button &oldButton)
{
    this->_isSelected = oldButton.getIsSelected();
    this->_cmd = oldButton.getCmd();
    this->_parameter = oldButton.getParameter();
}

void ecs::components::Button::setIsSelected(bool newState)
{
    _isSelected = newState;
}

bool ecs::components::Button::getIsSelected() const
{
    return _isSelected;
}

void ecs::components::Button::setCmd(const ecs::system::SystemResponse::CMD &newCmd)
{
    _cmd = newCmd;
}

const ecs::system::SystemResponse::CMD &ecs::components::Button::getCmd() const
{
    return _cmd;
}

void ecs::components::Button::setParameter(const std::string &newParameter)
{
    _parameter = newParameter;
}

const std::string &ecs::components::Button::getParameter() const
{
    return _parameter;
}

const std::type_index ecs::components::Button::getType() const
{
    return (std::type_index(typeid(Button)));
}

bool ecs::components::Button::operator==(Button &other)
{
    return other.getIsSelected() == this->_isSelected && other.getCmd() == this->_cmd && other.getParameter() == this->_parameter;
}