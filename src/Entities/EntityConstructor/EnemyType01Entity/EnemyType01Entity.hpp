/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** EnemyType01Entity.hpp
*/

#ifndef EnemyTYPE01ENTITY_HPP__
#define EnemyTYPE01ENTITY_HPP__

#include "IEntityConstructor.hpp"

namespace ecs::entities
{

class EnemyType01Entity : public IEntityConstructor
{
public:
    EnemyType01Entity() = default;
    ~EnemyType01Entity() = default;

    /**
     * @brief Create the entity associated with class constructor
     * 
     * @param entityManager 
     * @param componentsManager 
     * @return std::shared_ptr<ecs::entities::Entity> 
     */
    std::shared_ptr<ecs::entities::Entity> create(
        std::shared_ptr<IEntityManager> &entityManager,
        std::shared_ptr<ecs::components::IComponentManager> &componentsManager,
        std::pair<float, float> pos = std::make_pair(0,0),
        std::pair<float, float> velocity = std::make_pair(0,0),
        float rotation = 0) override;

    /**
     * @brief Get the Name entity
     * 
     * @return std::string 
     */
    std::string getName() override;
};
} // namespace ecs::entities

#endif //EnemyType01Entity_HPP__