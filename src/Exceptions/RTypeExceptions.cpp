/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** RTypeExceptions.cpp
*/

#include "RTypeExceptions.hpp"

RTypeExceptions::RTypeExceptions(std::string what, std::string where)
{
    this->_what = what;
    this->_where = where;
}

RTypeExceptions::~RTypeExceptions()
{
}

const char* RTypeExceptions::what() const noexcept
{
    return (this->_what.c_str());
}

const char* RTypeExceptions::where() const noexcept
{
    return (this->_where.c_str());
}