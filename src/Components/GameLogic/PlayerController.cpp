/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** PlayerController.cpp
*/

#include "PlayerController.hpp"

ecs::components::PlayerController::PlayerController(bool isPlayerOne) : _timer(500), _creationInterval(1), _isPlayerOne(isPlayerOne)
{
    _timer.start();
    _creationTimer.start();
    if (isPlayerOne) {
        _movementKeys[ecs::actions::UP] = ecs::input::UP;
        _movementKeys[ecs::actions::LEFT] = ecs::input::LEFT;
        _movementKeys[ecs::actions::DOWN] = ecs::input::DOWN;
        _movementKeys[ecs::actions::RIGHT] = ecs::input::RIGHT;
        _movementKeys[ecs::actions::SHOOT] = ecs::input::SPACE;
    }
    else {
        _movementKeys[ecs::actions::UP] = ecs::input::Z;
        _movementKeys[ecs::actions::LEFT] = ecs::input::Q;
        _movementKeys[ecs::actions::DOWN] = ecs::input::S;
        _movementKeys[ecs::actions::RIGHT] = ecs::input::D;
        _movementKeys[ecs::actions::SHOOT] = ecs::input::LEFT_SHIFT;
    }
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
    (void) other;
	return true;
}

const std::map<ecs::actions::Action, ecs::input::Key> &ecs::components::PlayerController::getMovementKeys(void) const
{
    return _movementKeys;
}

void ecs::components::PlayerController::setMovementKeys(std::map<ecs::actions::Action, ecs::input::Key> &newPlayerMovementKeys)
{
    _movementKeys = newPlayerMovementKeys;
}