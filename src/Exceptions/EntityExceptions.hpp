/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** EntityExceptions.hpp
*/

#ifndef ENTITYEXCEPTIONS_HPP
#define ENTITYEXCEPTIONS_HPP

#include <string>
#include "ECSExceptions.hpp"

/**
 * @brief Entity Class Exceptions
 * 
 */
class EntityExceptions : public ECSExceptions
{
private:
public:
    EntityExceptions(std::string, std::string);
    ~EntityExceptions();

};

#endif // ENTITYEXCEPTIONS_HPP