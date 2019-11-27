/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Velocity.hpp
*/

#ifndef VELOCITY_HPP
#define VELOCITY_HPP

#include "Motion.hpp"

namespace ecs::components
{
    /**
     * @brief Velocity describes the Velocity of an Entity
     * 
     */
    class Velocity : public Motion
    {
    private:
        float _velocityX;
        float _velocityY;
    public:
        Velocity(float x = 0,  float y = 0);
        Velocity(const Velocity &oldVelocity);
        ~Velocity();
        bool operator==(Velocity const &) const;

        /**
         * @brief Set the Velocity X object
         * 
         */
        void setVelocityX(const float &);
        
        /**
         * @brief Get the Velocity X object
         * 
         * @return float 
         */
        float getVelocityX() const;

        /**
         * @brief Set the Velocity Y object
         * 
         */
        void setVelocityY(const float &);
        
        /**
         * @brief Get the Velocity Y object
         * 
         * @return float 
         */
        float getVelocityY() const;

        /**
         * @brief Set the Velocity X and Y object
         * 
         */
        void setVelocity(const float &x, const float &y);

        /**
         * @brief Get the Velocity object
         * 
         * @return const std::pair<float, float> 
         */
        const std::pair<float, float> getVelocity() const;

        /**
         * @brief Get the Type object
         * 
         * @return const std::type_index 
         */
        const std::type_index getType() const override;
    };
}

#endif