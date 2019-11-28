/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** SystemConstructor.hpp
*/

#ifndef SYSTEMCONSTRUCTOR_HPP
#define SYSTEMCONSTRUCTOR_HPP

#include "ISystemConstructor.hpp"
#include "ManagerWrapper.hpp"

namespace ecs::system
{
template <typename T>
class SystemConstructor : public ISystemConstructor
{
private:
public:
    SystemConstructor(/* args */){};

    ~SystemConstructor(){};

    std::shared_ptr<ecs::system::ISystem> create(std::shared_ptr<ManagerWrapper> &managerWrapper,
                                                 std::list<int> &entitiesToDelete) override
    {
        return (std::make_shared<T>(managerWrapper, entitiesToDelete));
    };
};

} // namespace ecs::system

#endif // SYSTEMCONSTRUCTOR_HPP