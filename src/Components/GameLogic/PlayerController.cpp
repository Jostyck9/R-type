/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** PlayerController.cpp
*/

#include "PlayerController.hpp"

ecs::components::PlayerController::PlayerController() : _timer(500), _creationInterval(3)
{
    _timer.start();
    _creationTimer.start();
}

ecs::components::PlayerController::PlayerController(const PlayerController &oldPlayerController)
{
    _creationTimer.start();
    _creationInterval = oldPlayerController.getCreationInterval();
}

const std::type_index ecs::components::PlayerController::getType() const
{
    return (std::type_index(typeid(PlayerController)));
}

ecs::components::Timer &ecs::components::PlayerController::getTimer()
{
    return _timer;
}

double ecs::components::PlayerController::getCreationInterval() const
{
    return _creationInterval;
}

void ecs::components::PlayerController::setCreationInterval(double intervalSecond)
{
    _creationInterval = intervalSecond;
}

ecs::components::Timer &ecs::components::PlayerController::getCreationTimer()
{
    return _creationTimer;
}

bool ecs::components::PlayerController::operator==(PlayerController &other)
{
	return true;
}