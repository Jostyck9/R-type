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
#include "IEntityManager.hpp"
#include "IComponentManager.hpp"
#include "ISystem.hpp"

namespace ecs::system
{

    class ASystem : public ISystem
    {
    private:
        std::shared_ptr<entities::IEntityManager> &_entityManager;
        std::shared_ptr<components::IComponentManager> &_componentManager;
        std::list<int> &_entitiesToDelete;

    public:
        /**
         * @brief Construct a new System object
         * 
         * @param entityManager 
         * @param componentManager 
         * @param entitiesToDelete List of entities to delete after the update
         */
        ASystem(std::shared_ptr<entities::IEntityManager> &entityManager, std::shared_ptr<components::IComponentManager> &componentManager, std::list<int> &entitiesToDelete);
        ~ASystem();
    };
}

#endif //ASYSTEM_HPP__