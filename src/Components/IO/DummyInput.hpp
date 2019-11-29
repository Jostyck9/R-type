/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** DummyInput.hpp
*/

#ifndef DUMMYINPUT_HPP
#define DUMMYINPUT_HPP

#include "Input.hpp"

namespace ecs::components
{
    /**
     * @brief DummyInput describes the DummyInput of the Input of an Component
     * 
     */
    class DummyInput : public Input
    {
    private:
    public:
        DummyInput();
        ~DummyInput();

        /**
         * @brief Get the Type object
         * 
         * @return const std::type_index 
         */
        const std::type_index getType() const override;
    };
}


#endif