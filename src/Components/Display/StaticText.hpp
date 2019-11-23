/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** StaticText.hpp
*/

#ifndef STATICTEXT_HPP
#define STATICTEXT_HPP

#include <typeindex>
#include "Text.hpp"

namespace ecs::components
{
    /**
     * @brief StaticText describes an attribute that is a StaticText. 
     *
     */
    class StaticText : public Text

    {
    public:
        StaticText();
        ~StaticText();
        /**
         * @brief Get the Type object
         * 
         * @return const std::type_index 
         */
        const std::type_index getType() const;
    };
}

#endif //STATICTEXT_HPP