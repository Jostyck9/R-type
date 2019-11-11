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

namespace components
{
    /**
     * @brief Animator describes that the entity is animated 
     *
     */
    class Animator : public IDisplay

    {
    public:
        Animator() = default;
        virtual ~Animator() = 0;
        void setId(const unsigned int newId);
        const unsigned int getId(void) const;

    private:
        unsigned int _id;
    };
}

#endif //Animator_HPP