/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Timer.cpp
*/

#include "Timer.hpp"

ecs::components::Timer::Timer()
{
    _endTime = 0;
}

ecs::components::Timer::Timer(double endTime)
{
    _endTime = endTime;
}

ecs::components::Timer::Timer(const Timer &oldTimer)
{
    this->_startTime = oldTimer.getStart();
    this->_stopTime = oldTimer.getStop();
    this->_endTime = oldTimer.getEndTime();
}

ecs::components::Timer::~Timer()
{
}

bool ecs::components::Timer::operator==(Timer &other)
{
    return other.getStart() == this->_startTime && other.getStop() == this->_stopTime && other.getEndTime() == this->_endTime;
}

void ecs::components::Timer::start()
{
    _startTime = std::chrono::system_clock::now();
    _isRunning = true;
}

void ecs::components::Timer::stop()
{
    _stopTime = std::chrono::system_clock::now();
    _isRunning = false;
}

void ecs::components::Timer::restart()
{
    start();
}

void ecs::components::Timer::restart(double endTime)
{
    _endTime = endTime;
    start();
}

bool ecs::components::Timer::checkEndTimer()
{
    return _endTime <= std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - _startTime).count();
}

double ecs::components::Timer::getElapsedMilliseconds()
{
    std::chrono::time_point<std::chrono::system_clock> endTime;

    if(_isRunning) {
        endTime = std::chrono::system_clock::now();
    } else {
        endTime = _stopTime;
    }
    return std::chrono::duration_cast<std::chrono::milliseconds>(endTime - _startTime).count();
}

double ecs::components::Timer::getElapsedSeconds()
{
    return getElapsedMilliseconds() / 1000.0;
}

const std::chrono::time_point<std::chrono::system_clock> &ecs::components::Timer::getStart() const
{
    return _startTime;
}

const std::chrono::time_point<std::chrono::system_clock> &ecs::components::Timer::getStop() const
{
    return _stopTime;
}

double ecs::components::Timer::getEndTime() const
{
    return _endTime;
}

const std::type_index ecs::components::Timer::getType() const
{
    return (std::type_index(typeid(Timer)));
}