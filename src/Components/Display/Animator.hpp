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

namespace ecs::components
{
    /**
     * @brief Animator describes that the entity is animated 
     *
     */
    class Animator : public IDisplay

    {
    public:
        Animator();
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
        
    private:
        unsigned int _id;
    };
}

#endif //Animator_HPP