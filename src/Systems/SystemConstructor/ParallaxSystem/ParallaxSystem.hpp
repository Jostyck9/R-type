/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** ParallaxSystem.hpp
*/

#ifndef PARALLAXSYSTEM_HPP__
#define PARALLAXSYSTEM_HPP__

#include "Collision.hpp"
#include "Velocity.hpp"
#include "Rotation.hpp"
#include "Position.hpp"
#include "ASystem.hpp"
#include "SystemResponse.hpp"


namespace ecs::system
{
class ParallaxSystem : public ASystem
{

public:
    /**
     * @brief Construct a new Movement System object, Check the colision and move the entities
     * 
     * @param managerWrapper 
     * @param entitiesToDelete 
     */
    ParallaxSystem(std::shared_ptr<IManagerWrapper> &managerWrapper, std::shared_ptr<ecs::entities::IEntityFactory> &entityFactory, std::list<int> &entitiesToDelete);
    ~ParallaxSystem() = default;
    /**
     * @brief update
     * 
     * @return SystemResponse 
     */
    SystemResponse update() override;
};

} // namespace ecs::system

#endif //PARALLAXSYSTEM_HPP__