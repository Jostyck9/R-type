/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Level.hpp
*/

#ifndef LEVEL_HPP
#define LEVEL_HPP

#include <typeindex>
#include "UserInterface.hpp"

namespace components
{
    /**
     * @brief Level describes an attribute that stores a numeric value representing Level points. 
     *
     */
    class Level : public UserInterface

    {
    public:
        Level();
        ~Level();
        void setValue(const float &newValue);
        const float getValue(void) const;
        const bool operator==(Level &other);
    private:
        float _value;
    };
}

#endif //LEVEL_HPP