/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Item.hpp
*/

#ifndef ITEM_HPP
#define ITEM_HPP

#include <typeindex>
#include "IGameLogic.hpp"

namespace components
{
    /**
     * @brief Item describes an attribute that stores a numeric value representing Item points. 
     *
     */
    class Item : public IGameLogic

    {
    public:
        Item();
        ~Item();
        void setValue(const float &newValue);
        float getValue(void) const;
        bool operator==(Item &other);
        
    private:
        float _value;
    };
}

#endif //ITEM_HPP