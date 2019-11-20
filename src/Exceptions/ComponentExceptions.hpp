/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** ComponentExceptions.hpp
*/

#ifndef COMPONENTEXCEPTIONS_HPP
#define COMPONENTEXCEPTIONS_HPP

#include <string>
#include "ECSExceptions.hpp"

/**
 * @brief Component Class Exceptions
 * 
 */
class ComponentExceptions : public ECSExceptions
{
private:
public:
    ComponentExceptions(std::string);
    ~ComponentExceptions();

};

#endif // COMPONENTEXCEPTIONS_HPP