/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** EntityExceptions.cpp
*/

#include "EntityExceptions.hpp"

EntityExceptions::EntityExceptions(std::string what, std::string where) : ECSExceptions(what, where)
{
}

EntityExceptions::~EntityExceptions()
{
}