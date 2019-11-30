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
        ButtonColorSystem(std::shared_ptr<ecs::ManagerWrapper> &managerWrapper, std::shared_ptr<ecs::entities::IEntityFactory> &entityFactory, std::list<int> &entitiesToDelete);
        ~ButtonColorSystem() = default;

        SystemResponse update() override;
        const std::string getName() const override;
    };
}
#endif //BUTTONCOLORSYSTEM_HPP