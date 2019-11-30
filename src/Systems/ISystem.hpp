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
         * @brief Get the Name object
         * 
         * @return const std::string 
         */
        virtual const std::string getName() const = 0;

        /**
         * @brief update
         * 
         * @return SystemResponse 
         */
        virtual SystemResponse update() = 0;
    };

}

#endif //ISYSTEM_HPP__