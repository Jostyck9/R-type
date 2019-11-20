/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** DisplaySystem.hpp
*/

#ifndef DISPLAYSYSTEM_HPP__
#define DISPLAYSYSTEM_HPP__

#include <ctime>
#include "ASystem.hpp"

namespace ecs::system
{
    class DisplaySystem : public ASystem
    {
    public:
        DisplaySystem(std::shared_ptr<entities::IEntityManager> &entityManager, std::shared_ptr<ecs::components::IComponentManager> &componentManager, std::list<int> &entitiesToDelete);
        ~DisplaySystem();

        void update() override;

    private:

    time_t _elapsedTime;
    };
}

#endif //DISPLAYSYSTEM_HPP__