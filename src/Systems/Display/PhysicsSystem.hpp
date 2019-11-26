/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** PhysicsSystem.hpp
*/

#ifndef PHYSICSSYSTEM_HPP__
#define PHYSICSSYSTEM_HPP__

#include "ASystem.hpp"

namespace ecs::system
{
    class PhysicsSystem : public ASystem
    {
    public:
        PhysicsSystem(std::shared_ptr<ManagerWrapper> &managerWrapper, std::list<int> &entitiesToDelete);
        ~PhysicsSystem();

        void update() override;
    };
}

#endif //PHYSICSSYSTEM_HPP__