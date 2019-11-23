/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** ComponentExceptions.cpp
*/

#include "ComponentExceptions.hpp"

ComponentExceptions::ComponentExceptions(std::string what, std::string where) : ECSExceptions(what, where)
{
}

ComponentExceptions::~ComponentExceptions()
{
}

