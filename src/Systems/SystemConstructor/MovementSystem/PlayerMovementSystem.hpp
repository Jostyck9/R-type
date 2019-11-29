/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** PlayerMovementSystem.hpp
*/

#ifndef PLAYERMOVEMENTSYSTEM_HPP__
#define PLAYERMOVEMENTSYSTEM_HPP__

#include "Collision.hpp"
#include "Velocity.hpp"
#include "Rotation.hpp"
#include "Position.hpp"
#include "ASystem.hpp"
#include "Render/Input.hpp"
#include "PlayerController.hpp"


namespace ecs::system
{
class PlayerMovementSystem : public ASystem
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
public:
    /**
     * @brief Construct a new Movement System object, Check the colision and move the entities
     * 
     * @param managerWrapper 
     * @param entitiesToDelete 
     */
    PlayerMovementSystem(std::shared_ptr<ManagerWrapper> &managerWrapper, std::list<int> &entitiesToDelete);
    ~PlayerMovementSystem() = default;
    void update() override;
    void updateVelocityOnInput(std::map<ecs::input::Key, bool> &keys, std::shared_ptr<ecs::components::Velocity> &velocityComp);
};

} // namespace ecs::system

#endif //PLAYERMOVEMENTSYSTEM_HPP__