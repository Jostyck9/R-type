/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** DummyInput.cpp
*/

#include "DummyInput.hpp"

using namespace ecs::components;

DummyInput::DummyInput()
{
}

DummyInput::~DummyInput()
{
}

const std::type_index DummyInput::getType() const
{
    return (std::type_index(typeid(DummyInput)));
}