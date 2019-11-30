/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Animator.hpp
*/

#ifndef ANIMATOR_HPP
#define ANIMATOR_HPP

#include <typeindex>
#include "IDisplay.hpp"
#include "Rect.hpp"

namespace ecs::components
{
    /**
     * @brief Animator describes that the entity is animated 
     *
     */
    class Animator : public IDisplay

    {
    public:
        Animator(Rect &rect, int maxRep);
        Animator(const Animator &oldAnimator); 
        ~Animator();

         /**
         * @brief Set new value to the component id
         * 
         * @param newId 
         */
        void setId(const unsigned int &newId);
         /**
         * @brief return the component id
         * 
         */
        unsigned int getId(void) const;
        /**
         * @brief Get the Type object
         * 
         * @return const std::type_index 
         */
        const std::type_index getType() const;
        
        bool operator==(Animator &other);
        
        const ecs::Rect &getRect() const;

        const int &getMaxRep() const;
        const int &getCurrentRep() const;
        void setCurrentRep(int currentRep);

    private:
        unsigned int _id;
        ecs::Rect _rect;
        int _maxRep;
        int _currentRep;
    };
}

#endif //Animator_HPP