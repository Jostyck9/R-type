/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Damage.hpp
*/

#ifndef DAMAGE_HPP
#define DAMAGE_HPP

#include <typeindex>
#include "UserInterface.hpp"

namespace components
{
    /**
     * @brief Damage describes an attribute that stores a numeric value representing Damage points. 
     *
     */
    class Damage : public UserInterface

    {
    public:
        Damage();
        ~Damage();
        void setValue(const float &newValue);
        const float getValue(void) const;
        const bool operator==(Damage &other);
    private:
        float _value;
    };
}

#endif //DAMAGE_HPP