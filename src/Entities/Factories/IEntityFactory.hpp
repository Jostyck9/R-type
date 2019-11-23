/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** IFactory.hpp
*/

#ifndef IENTITYFACTORY_HPP__
#define IENTITYFACTORY_HPP__

#include <string>
#include <memory>
#include "IEntityConstructor.hpp"
#include "Entity.hpp"

namespace ecs::entities
{
class IEntityFactory
{
public:
    /**
     * @brief Create an Entity object with the specific name
     * 
     * @param name 
     * @return std::shared_ptr<Entity> 
     */
    virtual std::shared_ptr<Entity> createEntity(const std::string &name) = 0;

    /**
     * @brief Add an entityConstructor to use inside the factory
     * 
     * @param constructor 
     */
    virtual void addEntityConstructor(std::shared_ptr<IEntityConstructor> constructor) = 0;

    /**
     * @brief Create a Entity object
     * 
     * @param description
     * @return std::shared_ptr<Entity> 
     */
    // virtual std::shared_ptr<Entity> createEntity(/* Buffer de la socket provenant du serveur (reflechir pour la clsse) */ description) = 0;
};
} // namespace ecs::entities

#endif //IENTITYFACTORY_HPP__