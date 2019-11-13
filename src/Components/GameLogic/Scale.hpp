/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Scale.hpp
*/

#ifndef SCALE_HPP
#define SCALE_HPP

#include <typeindex>
#include "IGameLogic.hpp"

namespace components
{
    /**
     * @brief Scale describes an attribute that stores a numeric value representing Scale points. 
     *
     */
    class Scale : public IGameLogic

    {
    public:
        Scale();
        ~Scale();
        void setValue(const float &newValue);
        float getValue(void) const;
        bool operator==(Scale &other);
        
    private:
        float _value;
    };
}

#endif //SCALE_HPP