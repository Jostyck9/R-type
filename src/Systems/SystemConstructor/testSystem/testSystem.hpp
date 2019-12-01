/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** testSystem.hpp
*/

#ifndef TESTSYSTE_HPP
#define TESTSYSTE_HPP

#include "ISystemConstructor.hpp"
#include "IEntityManager.hpp"
#include "IComponentManager.hpp"

namespace ecs::system 
{
    class testSystem : public ISystemConstructor
    {
    private:
    public:
        testSystem();
        ~testSystem();

        /**
         * @brief create the test System
         * 
         * @param managerWrapper 
         * @param entityFactory 
         * @param entitiesToDelete 
         * @return std::shared_ptr<ecs::system::ISystem> 
         */
        std::shared_ptr<ecs::system::ISystem> create(std::shared_ptr<IManagerWrapper> &managerWrapper,
            std::shared_ptr<ecs::entities::IEntityFactory> &entityFactory,
            std::list<int> &entitiesToDelete) override;

        /**
         * @brief Get the Name object
         * 
         * @return std::string 
         */
        std::string getName() override;
    };
}
#endif //TESTSYSTE_HPP