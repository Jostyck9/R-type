/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Timer.hpp
*/

#ifndef TIMER_HPP
#define TIMER_HPP

#include <chrono>
#include <typeindex>
#include "IGameLogic.hpp"

namespace ecs::components
{
    /**
     * @brief Timer for all the game
     *
     */
    class Timer : public IGameLogic
    {
    public:
        Timer();
        Timer(double endTime);
        Timer(const Timer &oldTimer);
        ~Timer();

        bool operator==(Timer &other);

        /**
         * @brief Start timer
         *
         */
        void start();
        /**
         * @brief Stop timer
         *
         */
        void stop();
        /**
         * @brief Restart timer
         *
         */
        void restart();
        /**
         * @brief Restart timer with end time
         *
         * @param endTime
         */
        void restart(double endTime);
        /**
         * @brief Get time elapsed since the begin in milliseconds
         *
         */
        double getElapsedMilliseconds();
        /**
         * @brief Get time elapsed since the begin in seconds
         *
         */
        double getElapsedSeconds();

        const std::chrono::time_point<std::chrono::system_clock> &getStart() const;
        const std::chrono::time_point<std::chrono::system_clock> &getStop() const;
        double getEndTime() const;

        /**
         * @brief Check if the timer is finish
         *
         * @return bool
         */
        bool checkEndTimer();

        /**
        * @brief Get the Type object
        *
        * @return const std::type_index
        */
        const std::type_index getType() const;
    private:
        std::chrono::time_point<std::chrono::system_clock> _startTime;
        std::chrono::time_point<std::chrono::system_clock> _stopTime;
        double _endTime;
        bool _isRunning = false;
    };
}

#endif //DAMAGE_HPP