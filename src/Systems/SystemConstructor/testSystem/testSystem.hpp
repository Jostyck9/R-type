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

        std::shared_ptr<ecs::system::ISystem> create(
            std::shared_ptr<ecs::entities::IEntityManager> &entityManager,
            std::shared_ptr<ecs::components::IComponentManager> &componentsManager,
            std::list<int> &entitiesToDelete) override;

        std::string getName() override;
    };
}
#endif //TESTSYSTE_HPP