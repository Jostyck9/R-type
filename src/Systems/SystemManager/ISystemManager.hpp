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
    class ISystemManager
    {
    public:
        /**
         * @brief Update the game with all the systems inside the manager
         * 
         */
        virtual void updateAll() = 0;

        /**
         * @brief Get the Entities To Delete object
         * 
         * @return std::list<int>& 
         */
        virtual std::list<int> &getEntitiesToDelete() = 0;

        /**
         * @brief Add a system inside the system manager
         * 
         * @param system 
         */
        virtual void addSystem(std::shared_ptr<ISystem> system) = 0;

        /**
         * @brief Remove all the systems inside the system manager
         * 
         */
        virtual void deleteAll() = 0;

    };
}

#endif //ISYSTEMMANAGER_HPP__