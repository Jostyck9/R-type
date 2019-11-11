/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** IO.hpp
*/

#ifndef IO_HPP
#define IO_HPP

#include "IComponent.hpp"


namespace components
{
    /**
     * @brief IIsO describes the input output of an Component
     * 
     */
    class IIO : public IComponent
    {
    private:
    public:
        IIO() = default;
        virtual ~IIO() = 0;
    };
}

#endif