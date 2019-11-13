/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Level.hpp
*/

#ifndef LEVEL_HPP
#define LEVEL_HPP

#include <typeindex>
#include "IGameLogic.hpp"

namespace components
{
    /**
     * @brief Level describes an attribute that stores a numeric value representing Level points. 
     *
     */
    class Level : public IGameLogic

    {
    public:
        Level();
        ~Level();
        void setValue(const float &newValue);
        float getValue(void) const;
        bool operator==(Level &other);
    private:
        float _value;
    };
}

#endif //LEVEL_HPP