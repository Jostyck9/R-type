/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Collision.hpp
*/

#ifndef COLLISION_HPP
#define COLLISION_HPP

#include <string>
#include <map>
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
        std::map<size_t, std::string> _encounteredTag;
        std::string _tag;

    public:
        Collision(bool triggered = false, float x = 0, float y = 0, float width = 0, float height = 0, const std::string &tag = "");
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
         * @return const std::map<size_t, const std::string>& 
         */
        const std::map<size_t, std::string> &getCollidedTags() const;

        /**
         * @brief Clear all the Collided Tags
         * 
         */
        void clearTags();

        /**
         * @brief Add a tag in the encoutered collisions
         * 
         * @param idEntity 
         * @param tag 
         */
        void addTag(const size_t idEntity, const std::string &tag);

        /**
         * @brief Get the Tag object
         * 
         * @return const std::string& 
         */
        const std::string &getTag() const;

        /**
         * @brief Set the Tag object
         * 
         * @param tag 
         */
        void setTag(const std::string &tag);

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