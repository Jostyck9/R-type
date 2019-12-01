/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Power.hpp
*/

#ifndef POWER_HPP
#define POWER_HPP

#include <typeindex>
#include "IGameLogic.hpp"

namespace ecs::components
{
    /**
     * @brief Power describes an attribute that stores a numeric value representing Power points. 
     *
     */
    class Power : public IGameLogic

    {
    public:
        Power();
        Power(const Power &oldPower);
        ~Power();
        /**
         * @brief Set the Value object
         * 
         * @param newValue 
         */
        void setValue(const float &newValue);
        /**
         * @brief Get the Value object
         * 
         * @return float 
         */
        float getValue(void) const;
        /**
         * @brief Get the Type object
         * 
         * @return const std::type_index 
         */
        const std::type_index getType() const;
        bool operator==(Power &other);
    private:
        float _value;
    };
}

#endif //POWER_HPP