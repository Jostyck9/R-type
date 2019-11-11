/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Health.hpp
*/

#ifndef HEALTH_HPP
#define HEALTH_HPP

#include <typeindex>
#include "UserInterface.hpp"

namespace components
{
    /**
     * @brief Health describes an attribute that stores a numeric value representing Health points. 
     *
     */
    class Health : public UserInterface

    {
    public:
        Health();
        ~Health();
        void setValue(const float &newValue);
        const float getValue(void) const;

    private:
        float _value;
    };
}

#endif //HEALTH_HPP