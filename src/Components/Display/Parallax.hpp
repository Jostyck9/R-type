/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Parallax.hpp
*/

#ifndef PARALLAX_HPP
#define PARALLAX_HPP

#include <typeindex>
#include "IDisplay.hpp"
#include "Timer.hpp"
#include "Rect.hpp"

namespace ecs::components
{
    /**
     * @brief Parallax describes that the entity is animated 
     *
     */
    class Parallax : public IDisplay

    {
    public:
        Parallax(double intervalSecond, int move, int offset, Rect &origin);
        Parallax(const Parallax &oldParallax); 
        ~Parallax();
        
        /**
         * @brief Get the Rect object
         * 
         * @return const ecs::Rect& 
         */
        const ecs::Rect &getRect() const;

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
        
        bool operator==(Parallax &other);

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
         * @brief Get the obj's move
         * 
         * @return int 
         */
        int getMove() const;

        /**
         * @brief Set object's move
         * 
         * @param move 
         */
        void setMove(int &move);

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
        double _interval;
        int _move;
        Timer _timer;
        int _offset;
        Rect _origin;
    };
}

#endif //Parallax_HPP