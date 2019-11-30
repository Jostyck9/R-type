/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** PlayerController.cpp
*/

#include "PlayerController.hpp"

ecs::components::PlayerController::PlayerController()
{
}

ecs::components::PlayerController::PlayerController(const PlayerController &oldPlayerController)
{
}

const std::type_index ecs::components::PlayerController::getType() const
{
    return (std::type_index(typeid(PlayerController)));
}

bool ecs::components::PlayerController::operator==(PlayerController &other)
{
	return true;
}