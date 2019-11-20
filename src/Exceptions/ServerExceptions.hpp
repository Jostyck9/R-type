/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** ServerExceptions.hpp
*/

#ifndef SERVEREXCEPTIONS_HPP
#define SERVEREXCEPTIONS_HPP

#include <string>
#include "RTypeExceptions.hpp"

/**
 * @brief Server class Exception
 * 
 */
class ServerExceptions : public RTypeExceptions
{
public:
    ServerExceptions(std::string, std::string);
    ~ServerExceptions();
private:
};

#endif // SERVEREXCEPTIONS_HPP