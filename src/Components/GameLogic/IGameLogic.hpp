/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** IGameLogic.hpp
*/

#ifndef IGAMELOGIC_HPP
#define IGAMELOGIC_HPP

#include <typeindex>
#include "IComponent.hpp"

namespace ecs::components
{
    /**
     * @brief IGameLogic describes an attribute of an Entity that represent an ingame value
     *
     */
    class IGameLogic : public IComponent
    {};
}

#endif //IGAMELOGIC_HPP