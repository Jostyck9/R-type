/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** DefeatSystem.hpp
*/

#ifndef DEFEATSYSTEM_HPP
#define DEFEATSYSTEM_HPP

#include "ASystem.hpp"
#include "IEntityManager.hpp"
#include "IComponentManager.hpp"

namespace ecs::system 
{
    class DefeatSystem : public ASystem
    {
    private:
    public:
    /**
     * @brief Construct a new Defeat System object
     * 
     * @param managerWrapper 
     * @param entityFactory 
     * @param entitiesToDelete 
     */
        DefeatSystem(std::shared_ptr<IManagerWrapper> &managerWrapper, std::shared_ptr<ecs::entities::IEntityFactory> &entityFactory, std::list<int> &entitiesToDelete);
        ~DefeatSystem() = default;

        /**
         * @brief update
         * 
         * @return SystemResponse 
         */
        SystemResponse update() override;

    };
}
#endif //DEFEATSYSTEM_HPP