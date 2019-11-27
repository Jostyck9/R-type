/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** MovementSystem.hpp
*/

#ifndef MOVEMENTSYSTEM_HPP__
#define MOVEMENTSYSTEM_HPP__

#include "Velocity.hpp"
#include "Rotation.hpp"
#include "Position.hpp"
#include "ASystem.hpp"

namespace ecs::system
{

class MovementSystem : public ASystem
{
private:
    /* data */
public:
    MovementSystem(std::shared_ptr<entities::IEntityManager> &entityManager,
                   std::shared_ptr<ecs::components::IComponentManager> &componentManager,
                   std::list<int> &entitiesToDelete);
    ~MovementSystem();

    void updatePostion(
        std::shared_ptr<ecs::components::Position> pos, 
        std::shared_ptr<ecs::components::Rotation> rot, 
        std::shared_ptr<ecs::components::Velocity> speed);
    void update() override;
};

} // namespace ecs::system

#endif //MOVEMENTSYSTEM_HPP__