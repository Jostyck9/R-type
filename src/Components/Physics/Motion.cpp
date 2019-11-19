/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Motion.cpp
*/

#include "Motion.hpp"

using namespace ecs::components;

Motion::Motion()
{
}

Motion::~Motion()
{
}


bool Motion::operator==(Motion const &other) const
{
    (void) other;
    return (true);
}