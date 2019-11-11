/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** IPhysics.hpp
*/

#ifndef IPHYSICS_HPP
#define IPHYSICS_HPP

#include "IComponent.hpp"

namespace components
{
    /**
     * @brief IPhysics describes the physics of an Entity
     * 
     */
    class IPhysics : public IComponent
    {
    private:
    public:
        IPhysics() = default;
        virtual ~IPhysics() = 0;

        std::type_index getType() override;
    };
}

#endif