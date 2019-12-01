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
#include "Timer.hpp"

namespace ecs::system
{
class MovementSystem : public ASystem
{
private:

    /**
     * @brief Wrapper for an entity's components
     * 
     */
    struct data {
        std::shared_ptr<ecs::components::Position> pos;
        std::shared_ptr<ecs::components::Rotation> rot;
        std::shared_ptr<ecs::components::Velocity> speed;
        std::shared_ptr<ecs::components::Collision> box;
        std::pair<float, float> nextPos;
        std::shared_ptr<ecs::entities::Entity> entity;
    };

    ecs::components::Timer _myTimer;

public:
    /**
     * @brief Construct a new Movement System object, Check the colision and move the entities
     * 
     * @param managerWrapper 
     * @param entityFactory 
     * @param entitiesToDelete 
     */
    MovementSystem(std::shared_ptr<IManagerWrapper> &managerWrapper, std::shared_ptr<ecs::entities::IEntityFactory> &entityFactory, std::list<int> &entitiesToDelete);
    ~MovementSystem();

    /**
     * @brief Check if 2 boxColision are colliding
     * 
     * @param box1 
     * @param box2 
     * @return true 
     * @return false 
     */
    bool isColliding(const data &box1, const data &box2) const;

    /**
     * @brief Get the Next Pos for the entity
     * 
     * @param pos 
     * @param rot 
     * @param speed 
     * @return std::pair<float, float> (x,y)
     */
    std::pair<float, float> getNextPos(
        std::shared_ptr<ecs::components::Position> &pos,
        std::shared_ptr<ecs::components::Rotation> &rot,
        std::shared_ptr<ecs::components::Velocity> &speed);

    /**
     * @brief Update all the entities that are passed in parameters
     * 
     * @param all 
     */
    void updateAll(std::vector<data> &all);

    /**
     * @brief Update the position and the colisions
     * 
     */
    SystemResponse update() override;
};

} // namespace ecs::system

#endif //MOVEMENTSYSTEM_HPP__