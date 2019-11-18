/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** ISystemManager.hpp
*/

#ifndef ISYSTEMMANAGER_HPP__
#define ISYSTEMMANAGER_HPP__

namespace ecs::system
{
    class ISystemManager
    {
    public:
        /**
         * @brief Update the game with all the systems inside the manager
         * 
         */
        virtual void updateAll() = 0;
    };
}

#endif //ISYSTEMMANAGER_HPP__