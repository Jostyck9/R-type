/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** IComponent.hpp
*/

#ifndef ICOMPONENT_HPP_
#define ICOMPONENT_HPP_

#include <typeindex>

namespace ecs::components 
{
    /**
     * @brief Icomponent describes an attribute of an Entity
     * 
     */
    class IComponent
    {
    public:
        /**
         * @brief Get the Type of the component
         * 
         * @return std::type_index 
         */
        virtual const std::type_index getType() const = 0;
    };
}

#endif //ICOMPONENT_HPP_