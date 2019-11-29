/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** ILoader.hpp
*/

#ifndef ILOADER_HPP
#define ILOADER_HPP

#include <vector>
#include <memory>
#include "RTypeExceptions.hpp"

namespace ecs
{

template <typename T>
class ILoader
{
private:
public:
    /**
     * @brief get all libraries inside a file
     * 
     * @return std::vector<std::shared_ptr<T>> 
     */
    virtual std::vector<std::shared_ptr<T>> loadAllLibrary() = 0;

    /**
     * @brief get the define library given in parameter
     * 
     * @param const std::string
     * 
     * @return std::shared_ptr<T> 
     */
    virtual std::shared_ptr<T> loadLibrary(const std::string &) = 0;
};
}; // namespace ecs

#endif //ILOADER_HPP