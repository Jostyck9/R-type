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

namespace ecs::components
{
    /**
     * @brief Level describes an attribute that stores a numeric value representing Level points. 
     *
     */
    class Level : public IGameLogic

    {
    public:
        Level();
        Level(const Level &oldLevel);
        ~Level();
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
        bool operator==(Level &other);
    private:
        float _value;
    };
}

#endif //LEVEL_HPP