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

namespace components
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
    };
}

#endif //STATICTEXT_HPP