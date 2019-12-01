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

namespace ecs::components
{
    /**
     * @brief Scale describes an attribute that stores a numeric value representing Scale points. 
     *
     */
    class Scale : public IGameLogic

    {
    public:
        Scale();
        Scale(const Scale &oldScale);
        ~Scale();
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
        bool operator==(Scale &other);
        
    private:
        float _value;
    };
}

#endif //SCALE_HPP