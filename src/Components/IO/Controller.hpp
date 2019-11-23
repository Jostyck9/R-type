/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Controller.hpp
*/

#ifndef CONTROLLER_HPP
#define CONTROLER_HPP

#include "Input.hpp"

namespace ecs::components
{
    /**
     * @brief Controller describes the Controller of the Input of an Component
     * 
     */
    class Controller : public Input
    {
    private:
    public:
        Controller();
        ~Controller();
    };
}


#endif