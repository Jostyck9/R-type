/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Position.hpp
*/

#ifndef POSITION_HPP__
#define POSITION_HPP__

#include <utility>
#include "IPhysics.hpp"

namespace ecs::components
{
    class Position : public IPhysics
    {
    private:
        float _x;
        float _y;
    public:
        Position(float x = 0, float y = 0);
        Position(const Position &oldPosition);
        ~Position();

        bool operator==(Position const &) const;

        /**
         * @brief get the X position
         * 
         * @return float 
         */
        float getX() const;

        /**
         * @brief get the Y position
         * 
         * @return float 
         */
        float getY() const;

        /**
         * @brief Get the Position object
         * 
         * @return const std::pair<float, float> 
         */
        const std::pair<float, float> getPosition() const;

        /**
         * @brief set the X position
         * 
         * @param x 
         */
        void setX(float x);

        /**
         * @brief set the y position
         * 
         * @param y 
         */
        void serY(float y);

        /**
         * @brief Set the Position object
         * 
         * @param position 
         */
        void setPosition(const std::pair<float, float> position);

        const std::type_index getType() const override;
    };
}

#endif //POSITION_HPP__