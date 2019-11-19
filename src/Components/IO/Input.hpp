/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Input.hpp
*/

#ifndef INPUT_HPP
#define INPUT_HPP

#include "IIO.hpp"

namespace ecs::components
{
    /**
     * @brief Input describes the input of an Component
     * 
     */
    class Input : public IIO
    {
    private:
    public:
        Input();
        ~Input();
    };
}

#endif