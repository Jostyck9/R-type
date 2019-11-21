/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** SystemExceptions.cpp
*/

#include "SystemExceptions.hpp"

SystemExceptions::SystemExceptions(std::string what, std::string where) : ECSExceptions(what, where)
{

}

SystemExceptions::~SystemExceptions()
{
}