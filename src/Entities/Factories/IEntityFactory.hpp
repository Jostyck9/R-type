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
     * @brief Create a Entity object
     * 
     * @param description
     * @return std::shared_ptr<Entity> 
     */
    // virtual std::shared_ptr<Entity> createEntity(/* Buffer de la socket provenant du serveur (reflechir pour la clsse) */ description) = 0;
};
}

#endif //IENTITYFACTORY_HPP__