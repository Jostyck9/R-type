/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Collision.hpp
*/

#ifndef COLLISION_HPP
#define COLLISION_HPP

#include <list>
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

        bool _triggered;
        bool _collide;
        std::list<int> _encounteredTag;

    public:
        Collision(bool triggered = false, float x = 0, float y = 0, float width = 0, float height = 0);
        Collision(const Collision &oldCollision);
        ~Collision();
        bool operator==(Collision const &) const;

        /**
         * @brief Returns if the box is colliding with another
         * 
         * @return true if collinding
         * @return false if not collinding
         */
        bool isColliding() const;

        /**
         * @brief Set the Collinding object
         * 
         * @param isColliding 
         */
        void setCollinding(bool isColliding);

        /**
         * @brief Returns if it's a triggered collision box
         * 
         * @return true 
         * @return false 
         */
        bool isTriggered() const;

        /**
         * @brief Set the Triggered object
         * 
         * @param isTriggered 
         */
        void setTriggered(bool isTriggered);

        /**
         * @brief Get the Collided Tags object
         * 
         * @return const std::list<int>& 
         */
        const std::list<int> &getCollidedTags() const;

        /**
         * @brief Clear all the Collided Tags
         * 
         */
        void clearTags();

        /**
         * @brief Add a tag inside the cencountered collider's tag
         * 
         * @param tag 
         */
        void addTag(int tag);

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