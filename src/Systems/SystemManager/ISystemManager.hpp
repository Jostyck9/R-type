/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** ISystemManager.hpp
*/

#ifndef ISYSTEMMANAGER_HPP__
#define ISYSTEMMANAGER_HPP__

#include "ISystem.hpp"

namespace ecs::system
{
    class h
    {
    public:
        /**
         * @brief Update the game with all the systems inside the manager
         * 
         */
        virtual void updateAll() = 0;
        virtual std::list<int> &getEntitiesToDelete() = 0;
        virtual void addSystem(std::shared_ptr<ISystem> system) = 0;

    };
}

#endif //ISYSTEMMANAGER_HPP__