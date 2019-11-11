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
        void setId(unsigned int newId);
        unsigned int getId(void);

    private:
        unsigned int id;
    };
}

#endif //Animator_HPP