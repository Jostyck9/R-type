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

namespace ecs
{

template <typename T>
class ILoader
{
private:
public:
    ILoader() = default;
    ~ILoader() = default;

    virtual std::vector<std::shared_ptr<T>> loadAllLibrary() = 0;
    virtual std::shared_ptr<T> loadLibrary(const std::string &) = 0;
};
}; // namespace ecs

#endif //ILOADER_HPP