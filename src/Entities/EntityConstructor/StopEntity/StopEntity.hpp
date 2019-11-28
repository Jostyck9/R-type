/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** TestPlayerEntity.hpp
*/

#ifndef STOPENTITY_HPP__
#define STOPENTITY_HPP__

#include "IEntityConstructor.hpp"

namespace ecs::entities
{

class StopEntity : public IEntityConstructor
{
public:
    StopEntity() = default;
    ~StopEntity() = default;

    /**
     * @brief Create the entity associated with class constructor
     * 
     * @param entityManager 
     * @param componentsManager 
     * @return std::shared_ptr<ecs::entities::Entity> 
     */
    std::shared_ptr<ecs::entities::Entity> create(
        std::shared_ptr<IEntityManager> &entityManager,
        std::shared_ptr<ecs::components::IComponentManager> &componentsManager) override;

    /**
     * @brief Get the Name entity
     * 
     * @return std::string 
     */
    std::string getName() override;
};
} // namespace ecs::entities

#endif //STOPENTITY_HPP__