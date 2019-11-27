/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Collision.hpp
*/

#ifndef COLLISION_HPP
#define COLLISION_HPP

#include "IPhysics.hpp"

namespace ecs::components
{
    /**
     * @brief Collision describes the collision of an Entity and an other Entity
     * 
     */
    class Collision : public IPhysics
    {
    private:
        float _x;
        float _y;
        float _height;
        float _width;
    public:
        Collision(float x = 0, float y = 0, float width = 0, float height = 0);
        Collision(const Collision &oldCollision);
        ~Collision();
        bool operator==(Collision const &) const;

        /**
         * @brief Set the X object
         * 
         */
        void setX(const float &);
        /**
         * @brief Set the Y object
         * 
         */
        void setY(const float &);
        /**
         * @brief Set the Height object
         * 
         */
        void setHeight(const float &);
        /**
         * @brief Set the Width object
         * 
         */
        void setWidth(const float &);

        /**
         * @brief Get the X object
         * 
         * @return float 
         */
        float getX() const;
        /**
         * @brief Get the Y object
         * 
         * @return float 
         */
        float getY() const;
        /**
         * @brief Get the Height object
         * 
         * @return float 
         */
        float getHeight() const;
        /**
         * @brief Get the Width object
         * 
         * @return float 
         */
        float getWidth() const;
        /**
         * @brief Get the Type object
         * 
         * @return const std::type_index 
         */
        const std::type_index getType() const override;
    };
}

#endif