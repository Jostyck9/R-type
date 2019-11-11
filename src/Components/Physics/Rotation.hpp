/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Rotation.hpp
*/

#ifndef ROTATION_HPP
#define ROTATION_HPP

#include "IPhysics.hpp"

namespace components
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
        Rotation();
        ~Rotation();

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
        const float getRadAngle() const;
        /**
         * @brief Get the Type object
         * 
         * @return const std::type_index 
         */
        const std::type_index getType() const override;
    };
}

#endif