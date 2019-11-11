/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Velocity.hpp
*/

#ifndef VELOCITY_HPP
#define VELOCITY_HPP

#include "Motion.hpp"

namespace components
{
    /**
     * @brief Velocity describes the Velocity of an Entity
     * 
     */
    class Velocity : public Motion
    {
    private:
        float _value;
    public:
        Velocity();
        ~Velocity();
        const bool operator==(Velocity const &) const;

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
        const float getValue() const;
        /**
         * @brief Get the Type object
         * 
         * @return const std::type_index 
         */
        const std::type_index getType() const override;
    };
}

#endif