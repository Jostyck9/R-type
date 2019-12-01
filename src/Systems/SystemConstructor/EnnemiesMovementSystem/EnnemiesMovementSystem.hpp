/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** EnnemiesMovementSystem.hpp
*/

#ifndef ENNEMIESMOVEMENTSYSTEM_HPP__
#define ENNEMIESMOVEMENTSYSTEM_HPP__

#include "Collision.hpp"
#include "Velocity.hpp"
#include "Rotation.hpp"
#include "Position.hpp"
#include "ASystem.hpp"
#include "Render/Input.hpp"
#include "EnnemiesController.hpp"


namespace ecs::system
{

class EnnemiesMovementSystem : public ASystem
{
public:
    /**
     * @brief Construct a new Movement System object, Check the colision and move the entities
     * 
     * @param managerWrapper 
     * @param entitiesToDelete 
     */
    EnnemiesMovementSystem(std::shared_ptr<IManagerWrapper> &managerWrapper, std::shared_ptr<ecs::entities::IEntityFactory> &entityFactory, std::list<int> &entitiesToDelete);
    ~EnnemiesMovementSystem() = default;
    SystemResponse update() override;
    void updateVelocityOnPattern(std::shared_ptr<ecs::components::EnnemiesController> &controller, std::shared_ptr<ecs::components::Velocity> &velocityComp);
};

} // namespace ecs::system

#endif //ENNEMIESMOVEMENTSYSTEM_HPP__