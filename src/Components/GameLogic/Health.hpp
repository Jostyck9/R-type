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
        Health(int hp);
        Health(const Health &oldHealth);
        ~Health();
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
        bool operator==(Health &other);
    private:
        float _value;
    };
}

#endif //HEALTH_HPP