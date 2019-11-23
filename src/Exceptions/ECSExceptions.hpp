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

/**
 * @brief ECS Class Esception which manage exceptions of Entity, Components and System
 * 
 */
class ECSExceptions : public RTypeExceptions
{
private:
public:
    ECSExceptions(std::string, std::string);
    ~ECSExceptions();

};

#endif // ECSEXCEPTIONS_HPP