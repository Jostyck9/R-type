/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** PlayerController.hpp
*/

#ifndef PLAYERCONTROLLER_HPP
#define PLAYERCONTROLLER_HPP

#include <typeindex>
#include "IGameLogic.hpp"

namespace ecs::components
{
    /**
     * @brief PlayerController is used to recognize player entity
     *
     */
    class PlayerController : public IGameLogic
    {
    public:
        PlayerController();
        PlayerController(const PlayerController &oldPlayerController);
        ~PlayerController() = default;
        /**
         * @brief Get the Type object
         * 
         * @return const std::type_index 
         */
        const std::type_index getType() const override;
        bool operator==(PlayerController &other);
    };
}

#endif //PLAYERCONTROLLER_HPP