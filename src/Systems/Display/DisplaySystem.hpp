/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** DisplaySystem.hpp
*/

#ifndef DISPLAYSYSTEM_HPP__
#define DISPLAYSYSTEM_HPP__

#include "ASystem.hpp"

namespace ecs::system
{
    class DisplaySystem : public ASystem
    {
    public:
        DisplaySystem(std::shared_ptr<entities::IEntityManager> &entityManager, std::shared_ptr<components::IComponentManager> &componentManager, std::list<int> &entitiesToDelete);
        ~DisplaySystem();

        void update() override;
    };
}

#endif //DISPLAYSYSTEM_HPP__