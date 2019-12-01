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
        /**
         * @brief Construct a new Button Color System object
         * 
         * @param managerWrapper 
         * @param entityFactory 
         * @param entitiesToDelete 
         */
        ButtonColorSystem(std::shared_ptr<ecs::IManagerWrapper> &managerWrapper, std::shared_ptr<ecs::entities::IEntityFactory> &entityFactory, std::list<int> &entitiesToDelete);
        ~ButtonColorSystem() = default;

        /**
         * @brief update
         * 
         * @return SystemResponse 
         */

        SystemResponse update() override;

    };
}
#endif //BUTTONCOLORSYSTEM_HPP