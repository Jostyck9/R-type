/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Gravity.hpp
*/

#ifndef GRAVITY_HPP
#define GRAVITY_HPP

#include "IPhysics.hpp"

namespace ecs::components
{
    /**
     * @brief Gravity describes the gravity of an Entity
     * 
     */
    class Gravity : public IPhysics
    {
    private:
        float _value;
    public:
        Gravity();
        Gravity(const Gravity &oldGravity);
        ~Gravity();
        bool operator==(Gravity const &) const;
        
        /**
         * @brief Set the Value object
         * 
         */
        void setValue(const float &);

        /**
         * @brief Get the Value object
         * 
         * @return const float 
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