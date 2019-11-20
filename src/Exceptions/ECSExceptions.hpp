/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** ECSExceptions.hpp
*/

#ifndef ECSEXCEPTIONS_HPP
#define ECSEXCEPTIONS_HPP

#include <string>
#include "RTypeExceptions.hpp"

class ECSExceptions : public RTypeExceptions
{
private:
public:
    ECSExceptions(std::string);
    ~ECSExceptions();

};

#endif // ECSEXCEPTIONS_HPP