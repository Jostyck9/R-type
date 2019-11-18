/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** ISystem.hpp
*/

#ifndef ISYSTEM_HPP__
#define ISYSTEM_HPP__

namespace ecs::system
{

    class ISystem
    {
    public:
        virtual void update() = 0;
    };

}

#endif //ISYSTEM_HPP__