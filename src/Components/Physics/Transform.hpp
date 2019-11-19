/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Transform.hpp
*/

#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP

#include "IPhysics.hpp"

namespace ecs::components
{
    /**
     * @brief Transform describes the Transform of an Entity
     * 
     */
    class Transform : public IPhysics
    {
    private:
        float _value;
    public:
        Transform();
        ~Transform();
        bool operator==(Transform const &) const;

        /**
         * @brief Set the Value object
         * 
         */
        void setValue(const float &);

        /**
         * @brief Get the Value object
         * 
         * @return float 
         */
        float getValue() const;
        /**
         * @brief Get the Type object
         * 
         * @return const std::type_index 
         */
        const std::type_index getType() const override;
    };
}

#endif