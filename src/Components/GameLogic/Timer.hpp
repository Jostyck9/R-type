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
    class Timer : public IGameLogic
    {
    public:
        Timer();
        Timer(double endTime);
        Timer(const Timer &oldTimer);
        ~Timer();

        bool operator==(Timer &other);

        void start();
        void stop();
        void restart();
        void restart(double endTime);
        double getElapsedMilliseconds();
        double getElapsedSeconds();

        const std::chrono::time_point<std::chrono::system_clock> &getStart() const;
        const std::chrono::time_point<std::chrono::system_clock> &getStop() const;
        double getEndTime() const;

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