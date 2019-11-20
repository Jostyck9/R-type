/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** RTypeExceptions.hpp
*/

#ifndef RTYPEEXCEPTIONS_HPP
#define RTYPEEXCEPTIONS_HPP

#include <string>

/**
 * @brief Rtype Class Exception which regroup all Exceptions
 * 
 */
class RTypeExceptions : public std::exception 
{
private:
    std::string _what;
    std::string _where;
public:
    RTypeExceptions(std::string, std::string);
    ~RTypeExceptions();

    /**
     * @brief what exception for Server, System, Componenet, Entity and ECS
     * 
     * @return const char* 
     */
    const char *what() const noexcept override;
    /**
     * @brief where exception for Server, System, Componenet, Entity and ECS
     * 
     * @return const char* 
     */
    const char *where() const noexcept;
};

#endif //RTYPEEXCEPTIONS_HPP