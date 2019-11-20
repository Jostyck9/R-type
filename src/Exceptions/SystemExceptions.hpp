/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** SystemExceptions.hpp
*/

#ifndef SYSTEMEXCEPTIONS_HPP
#define SYSTEMEXCEPTIONS_HPP

#include <string>
#include "ECSExceptions.hpp"


/**
 * @brief System class Exception
 * 
 */
class SystemExceptions : public ECSExceptions
{
private:
public:
    SystemExceptions(std::string, std::string);
    ~SystemExceptions();

};

#endif //SYSTEMEXCEPTIONS_HPP