/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** ISystem.hpp
*/

#ifndef ISYSTEM_HPP__
#define ISYSTEM_HPP__

#include "SystemResponse.hpp"

namespace ecs::system
{

    class ISystem
    {
    public:
        /**
         * @brief update the game with this system
         * 
         */
        virtual SystemResponse update() = 0;
    };

}

#endif //ISYSTEM_HPP__