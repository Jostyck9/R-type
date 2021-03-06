/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** IDisplay.hpp
*/

#ifndef IDISPLAY_HPP
#define IDISPLAY_HPP

#include <typeindex>
#include "IComponent.hpp"

namespace ecs::components
{
    /**
     * @brief IDisplay describes an attribute of an Entity that is displayable
     *
     */
    class IDisplay : public IComponent
    {
    public:
        IDisplay() = default;
    };
}

#endif //IDISPLAY_HPP