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
#include "IEntityFactory.hpp"

namespace ecs::system
{

    class ASystem : public ISystem
    {
    protected:
        std::shared_ptr<IManagerWrapper> &_managerWrapper;
        std::shared_ptr<ecs::entities::IEntityFactory> &_entityFactory;
        std::list<int> &_entitiesToDelete;

    public:
        /**
         * @brief Construct a new System object
         * 
         * @param entityManager 
         * @param componentManager 
         * @param entitiesToDelete List of entities to delete after the update
         */
        ASystem(std::shared_ptr<IManagerWrapper> &managerWrapper, std::shared_ptr<ecs::entities::IEntityFactory> &entityFactory, std::list<int> &entitiesToDelete);
        ~ASystem();
    };
}

#endif //ASYSTEM_HPP__