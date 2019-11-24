/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Rotation.hpp
*/

#ifndef ROTATION_HPP
#define ROTATION_HPP

#include "IPhysics.hpp"

namespace ecs::components
{
    /**
     * @brief Rotation describes the Rotation of an Entity
     * 
     */
    class Rotation : public IPhysics
    {
    private:
        float _radAngle;
    public:
        /**
         * @brief Construct a new Rotation object
         * 
         * @param rotation in degree
         */
        Rotation(const float rotation = 0);
        Rotation(const Rotation &oldRotation);
        ~Rotation();
        bool operator==(Rotation const &) const;

        /**
         * @brief Set the Rad Angle object
         * 
         */
        void setRadAngle(const float &);

        /**
         * @brief Get the Rad Angle object
         * 
         * @return float 
         */
        float getRadAngle() const;
        /**
         * @brief Get the Type object
         * 
         * @return const std::type_index 
         */
        const std::type_index getType() const override;
    };
}

#endif