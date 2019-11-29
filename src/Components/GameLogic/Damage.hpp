/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Damage.hpp
*/

#ifndef DAMAGE_HPP
#define DAMAGE_HPP

#include <typeindex>
#include "IGameLogic.hpp"

namespace ecs::components
{
    /**
     * @brief Damage describes an attribute that stores a numeric value representing Damage points. 
     *
     */
    class Damage : public IGameLogic
    {
    public:
        Damage();
        Damage(int dmg);
        Damage(const Damage &oldDamage);
        ~Damage();
        void setValue(const float &newValue);
        float getValue(void) const;
        /**
         * @brief Get the Type object
         * 
         * @return const std::type_index 
         */
        const std::type_index getType() const;
        bool operator==(Damage &other);
    private:
        float _value;
    };
}

#endif //DAMAGE_HPP