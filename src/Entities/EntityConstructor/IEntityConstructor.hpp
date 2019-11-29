/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** IEntityConstructor.hpp
*/

#ifndef IENTITYCONSTRUCTOR_HPP__
#define IENTITYCONSTRUCTOR_HPP__

#include <memory>
#include <string>
#include "Entity.hpp"
#include "IEntityManager.hpp"
#include "IComponentManager.hpp"

namespace ecs::entities
{

class IEntityConstructor
{
public:
    /**
     * @brief Create an entity associated with the class
     * 
     * @param entityManager 
     * @param componentsManager 
     * @return std::shared_ptr<ecs::entities::Entity> 
     */
    virtual std::shared_ptr<ecs::entities::Entity> create(
        std::shared_ptr<IEntityManager> &entityManager,
        std::shared_ptr<ecs::components::IComponentManager> &componentsManager,
        std::pair<float, float> pos = std::make_pair(0,0),
        std::pair<float, float> velocity = std::make_pair(0,0),
        float rotation = 0) = 0;

    /**
     * @brief Get the Name of the entity
     * 
     * @return std::string 
     */
    virtual std::string getName() = 0;
};

} // namespace ecs::entities

#endif //IENTITYCONSTRUCTOR_HPP__