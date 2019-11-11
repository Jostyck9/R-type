/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Collision.hpp
*/

#ifndef COLLISION_HPP
#define COLLISION_HPP

#include "IPhysics.hpp"

namespace components
{
    /**
     * @brief Collision describes the collision of an Entity and an other Entity
     * 
     */
    class Collision : public IPhysics
    {
    private:
        int _x;
        int _y;
        float _height;
        float _width;
    public:
        Collision();
        ~Collision();

        /**
         * @brief Set the X object
         * 
         */
        void setX(const int &);
        /**
         * @brief Set the Y object
         * 
         */
        void setY(const int &);
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
         * @return int 
         */
        const int getX() const;
        /**
         * @brief Get the Y object
         * 
         * @return int 
         */
        const int getY() const;
        /**
         * @brief Get the Height object
         * 
         * @return float 
         */
        const float getHeight() const;
        /**
         * @brief Get the Width object
         * 
         * @return float 
         */
        const float getWidth() const;
        /**
         * @brief Get the Type object
         * 
         * @return const std::type_index 
         */
        const std::type_index getType() const override;
    };
}

#endif