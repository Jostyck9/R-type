/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** RTypeExceptions.hpp
*/

#ifndef RTYPEEXCEPTIONS_HPP
#define RTYPEEXCEPTIONS_HPP

#include <string>

class RTypeExceptions : public std::exception 
{
private:
    std::string _error;
public:
    RTypeExceptions(std::string);
    ~RTypeExceptions();

    const char *what() const noexcept override;
};

#endif //RTYPEEXCEPTIONS_HPP