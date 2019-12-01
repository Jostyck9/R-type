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
public:
    /**
     * @brief Construct a new Movement System object, Check the colision and move the entities
     * 
     * @param managerWrapper 
     * @param entityFactory
     * @param entitiesToDelete 
     */
    PlayerMovementSystem(std::shared_ptr<IManagerWrapper> &managerWrapper, std::shared_ptr<ecs::entities::IEntityFactory> &entityFactory, std::list<int> &entitiesToDelete);
    ~PlayerMovementSystem() = default;
    /**
     * @brief update
     * 
     * @return SystemResponse 
     */
    SystemResponse update() override;
    /**
     * @brief update the player velocity from his inputs
     * 
     * @param keys 
     * @param velocityComp 
     */
    void updateVelocityOnInput(std::map<ecs::input::Key, IRenderManager::KEY_STATE> &keys, std::shared_ptr<ecs::components::Velocity> &velocityComp);
};

} // namespace ecs::system

#endif //PLAYERMOVEMENTSYSTEM_HPP__