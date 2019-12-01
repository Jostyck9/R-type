/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** EnemiesMovementSystem.hpp
*/

#ifndef EnemiesMOVEMENTSYSTEM_HPP__
#define EnemiesMOVEMENTSYSTEM_HPP__

#include "Collision.hpp"
#include "Velocity.hpp"
#include "Rotation.hpp"
#include "Position.hpp"
#include "ASystem.hpp"
#include "Render/Input.hpp"
#include "EnemiesController.hpp"

namespace ecs::system
{

class EnemiesMovementSystem : public ASystem
{
public:
    /**
     * @brief Construct a new Movement System object, Check the colision and move the entities
     * 
     * @param managerWrapper
     * @param entityFactory 
     * @param entitiesToDelete 
     */
    EnemiesMovementSystem(std::shared_ptr<IManagerWrapper> &managerWrapper, std::shared_ptr<ecs::entities::IEntityFactory> &entityFactory, std::list<int> &entitiesToDelete);
    ~EnemiesMovementSystem() = default;
    /**
     * @brief update
     * 
     * @return SystemResponse 
     */
    SystemResponse update() override;
    /**
     * @brief update the velocity from the player and his position
     * 
     * @param controller 
     * @param velocityComp 
     * @param playerPos 
     * @param pos 
     */
    void updateVelocityOnPattern(std::shared_ptr<ecs::components::EnemiesController> &controller, std::shared_ptr<ecs::components::Velocity> &velocityComp, std::shared_ptr<ecs::components::Position> playerPos, std::shared_ptr<ecs::components::Position> pos);
    /**
     * @brief summon random ennemies  on the map
     * 
     * @param controller 
     */
    void spawnRandomEnemies(std::shared_ptr<ecs::components::PlayerController> &controller);
};

} // namespace ecs::system

#endif //EnemiesMOVEMENTSYSTEM_HPP__