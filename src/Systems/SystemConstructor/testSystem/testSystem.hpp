/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** testSystem.hpp
*/

#ifndef TESTSYSTEM_HPP
#define TESTSYSTEM_HPP

#include "ISystemConstructor.hpp"
#include "IEntityManager.hpp"
#include "IComponentManager.hpp"

namespace ecs::system 
{
    class testSystem : public ISystemConstructor
    {
    private:
    public:
        testSystem(std::shared_ptr<ecs::ManagerWrapper> &managerWrapper, std::list<int> &entitiesToDelete);
        ~testSystem();

        std::shared_ptr<ecs::system::ISystem> create(std::shared_ptr<ManagerWrapper> &managerWrapper,
            std::shared_ptr<ecs::entities::IEntityFactory> &entityFactory,
            std::list<int> &entitiesToDelete) override;
    };
}
#endif //TESTSYSTEM_HPP