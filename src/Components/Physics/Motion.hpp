/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Motion.hpp
*/

#ifndef MOTION_HPP
#define MOTION_HPP

#include "IPhysics.hpp"

namespace components
{
    /**
     * @brief Motion describes the Motion like the Velocity and the Acceleration of an Entity
     * 
     */
    class Motion : public IPhysics
    {
    private:
    public:
        Motion();
        ~Motion();
    };
}

#endif