/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** MovementSystem.hpp
*/

#ifndef MOVEMENTSYSTEM_HPP__
#define MOVEMENTSYSTEM_HPP__

#include "Collision.hpp"
#include "Velocity.hpp"
#include "Rotation.hpp"
#include "Position.hpp"
#include "ASystem.hpp"

namespace ecs::system
{

class MovementSystem : public ASystem
{
private:
    struct data {
        std::shared_ptr<ecs::components::Position> pos;
        std::shared_ptr<ecs::components::Rotation> rot;
        std::shared_ptr<ecs::components::Velocity> speed;
        std::shared_ptr<ecs::components::Collision> box;
        std::pair<float, float> nextPos;
        std::shared_ptr<ecs::entities::Entity> entity;
    };

public:
    MovementSystem(std::shared_ptr<ManagerWrapper> &managerWrapper, std::list<int> &entitiesToDelete);
    ~MovementSystem();

    bool isColliding(const data &box1, const data &box2) const;

    std::pair<float, float> getNextPos(
        std::shared_ptr<ecs::components::Position> &pos,
        std::shared_ptr<ecs::components::Rotation> &rot,
        std::shared_ptr<ecs::components::Velocity> &speed);

    void updateAll(std::vector<data> &all);

    void update() override;
};

} // namespace ecs::system

#endif //MOVEMENTSYSTEM_HPP__