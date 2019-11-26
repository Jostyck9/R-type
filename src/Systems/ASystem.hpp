/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** ASystem.hpp
*/

#ifndef ASYSTEM_HPP__
#define ASYSTEM_HPP__

#include <memory>
#include <list>
#include "ISystem.hpp"
#include "ManagerWrapper.hpp"

namespace ecs::system
{

    class ASystem : public ISystem
    {
    protected:
        std::shared_ptr<ManagerWrapper> &_managerWrapper;
        std::list<int> &_entitiesToDelete;

    public:
        /**
         * @brief Construct a new System object
         * 
         * @param entityManager 
         * @param componentManager 
         * @param entitiesToDelete List of entities to delete after the update
         */
        ASystem(std::shared_ptr<ManagerWrapper> &managerWrapper, std::list<int> &entitiesToDelete);
        ~ASystem();
    };
}

#endif //ASYSTEM_HPP__