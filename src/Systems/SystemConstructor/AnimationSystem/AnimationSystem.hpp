/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** AnimationSystem.hpp
*/

#ifndef ANIMATIONSYSTEM_HPP__
#define ANIMATIONSYSTEM_HPP__

#include "Collision.hpp"
#include "Velocity.hpp"
#include "Rotation.hpp"
#include "Position.hpp"
#include "ASystem.hpp"
#include "SystemResponse.hpp"


namespace ecs::system
{
class AnimationSystem : public ASystem
{

public:
    /**
     * @brief Construct a new Movement System object, Check the colision and move the entities
     * 
     * @param managerWrapper 
     * @param entitiesToDelete 
     */
    AnimationSystem(std::shared_ptr<ManagerWrapper> &managerWrapper, std::shared_ptr<ecs::entities::IEntityFactory> &entityFactory, std::list<int> &entitiesToDelete);
    ~AnimationSystem() = default;
    SystemResponse update() override;
};

} // namespace ecs::system

#endif //ANIMATIONSYSTEM_HPP__