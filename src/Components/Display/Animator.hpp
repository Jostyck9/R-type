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
#include "Timer.hpp"
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
        Animator(Rect &rect, int maxRep, double intervalSecond = 0.5);
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
        
        /**
         * @brief Get the Rect object
         * 
         * @return const ecs::Rect& 
         */
        const ecs::Rect &getRect() const;

        /**
         * @brief Get the Max Rep object
         * 
         * @return const int& 
         */
        const int &getMaxRep() const;

        /**
         * @brief Get the Current Rep object
         * 
         * @return const int& 
         */
        const int &getCurrentRep() const;

        /**
         * @brief Set the Current Rep object
         * 
         * @param currentRep 
         */
        void setCurrentRep(int currentRep);

        /**
         * @brief Get the Interval object
         * 
         * @return double 
         */
        double getInterval() const;

        /**
         * @brief Set the Interval object
         * 
         * @param intervalSecond 
         */
        void setInterval(double intervalSecond);

        /**
         * @brief Get the obj's offset
         * 
         * @return int 
         */
        int getOffset() const;

        /**
         * @brief Set object's offset
         * 
         * @param offset 
         */
        void setOffset(int &offset);

        /**
         * @brief Get the Timer object
         * 
         * @return Timer& 
         */
        Timer &getTimer();

    private:
        unsigned int _id;
        ecs::Rect _rect;
        int _maxRep;
        int _currentRep;
        double _interval;
        Timer _timer;
        int _offset;
    };
}

#endif //Animator_HPP