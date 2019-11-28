/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** TestPlayerEntity.hpp
*/

#ifndef PLAYENTITY_HPP__
#define PLAYENTITY_HPP__

#include "IEntityConstructor.hpp"

namespace ecs::entities
{

class PlayEntity : public IEntityConstructor
{
public:
    PlayEntity() = default;
    ~PlayEntity() = default;

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

#endif //PLAYENTITY_HPP__