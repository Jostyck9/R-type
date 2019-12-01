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
    /**
     * @brief Construct a new Menu System object
     * 
     * @param managerWrapper 
     * @param entityFactory 
     * @param entitiesToDelete 
     */
        MenuSystem(std::shared_ptr<IManagerWrapper> &managerWrapper, std::shared_ptr<ecs::entities::IEntityFactory> &entityFactory, std::list<int> &entitiesToDelete);
        ~MenuSystem() = default;

        /**
         * @brief update
         * 
         * @return SystemResponse 
         */
        SystemResponse update() override;

    };
}
#endif //MENUSYSTEM_HPP