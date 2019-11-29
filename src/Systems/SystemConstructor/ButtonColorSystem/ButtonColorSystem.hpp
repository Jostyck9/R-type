/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** ButtonColorSystem.hpp
*/

#ifndef BUTTONCOLORSYSTEM_HPP
#define BUTTONCOLORSYSTEM_HPP

#include "ASystem.hpp"
#include "IEntityManager.hpp"
#include "IComponentManager.hpp"

namespace ecs::system 
{
    class ButtonColorSystem : public ASystem
    {
    private:
    public:
        ButtonColorSystem(std::shared_ptr<ManagerWrapper> &managerWrapper, std::list<int> &entitiesToDelete);
        ~ButtonColorSystem() = default;

        SystemResponse update() override;

    };
}
#endif //BUTTONCOLORSYSTEM_HPP