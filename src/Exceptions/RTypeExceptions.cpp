/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** RTypeExceptions.cpp
*/

#include "RTypeExceptions.hpp"

RTypeExceptions::RTypeExceptions(std::string str)
{
    this->_error = str;
}

RTypeExceptions::~RTypeExceptions()
{
}

const char* RTypeExceptions::what() const noexcept
{
    return (this->_error.c_str());
}