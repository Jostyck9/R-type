/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Scale.hpp
*/

#ifndef SCALE_HPP
#define SCALE_HPP

#include <typeindex>
#include "UserInterface.hpp"

namespace components
{
    /**
     * @brief Scale describes an attribute that stores a numeric value representing Scale points. 
     *
     */
    class Scale : public UserInterface

    {
    public:
        Scale();
        ~Scale();
        void setValue(const float &newValue);
        const float getValue(void) const;

    private:
        float _value;
    };
}

#endif //SCALE_HPP