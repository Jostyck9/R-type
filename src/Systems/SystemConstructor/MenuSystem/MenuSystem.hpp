/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** MenuSystem.hpp
*/

#ifndef MENUSYSTEM_HPP
#define MENUSYSTEM_HPP

#include "ASystem.hpp"
#include "IEntityManager.hpp"
#include "IComponentManager.hpp"

namespace ecs::system 
{
    class MenuSystem : public ASystem
    {
    private:
    public:
        MenuSystem(std::shared_ptr<ManagerWrapper> &managerWrapper, std::list<int> &entitiesToDelete);
        ~MenuSystem() = default;

        SystemResponse update() override;

    };
}
#endif //MENUSYSTEM_HPP