/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Health.hpp
*/

#ifndef HEALTH_HPP
#define HEALTH_HPP

#include <typeindex>
#include "IGameLogic.hpp"

namespace ecs::components
{
    /**
     * @brief Health describes an attribute that stores a numeric value representing Health points. 
     *
     */
    class Health : public IGameLogic

    {
    public:
        Health();
        ~Health();
        void setValue(const float &newValue);
        float getValue(void) const;
        bool operator==(Health &other);
    private:
        float _value;
    };
}

#endif //HEALTH_HPP