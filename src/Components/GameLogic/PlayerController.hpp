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
#include "Timer.hpp"
#include <map>
#include "Input.hpp"
#include "Actions.hpp"

namespace ecs::components
{
    /**
     * @brief PlayerController is used to recognize player entity
     *
     */
    class PlayerController : public IGameLogic
    {
    public:
        PlayerController(bool isPlayerOne);
        PlayerController(const PlayerController &oldPlayerController);
        ~PlayerController() = default;
        /**
         * @brief Get the Type object
         * 
         * @return const std::type_index 
         */
        const std::type_index getType() const override;
        /**
         * @brief Get the Interval object
         * 
         * @return double 
         */
        double getCreationInterval() const;

        /**
         * @brief Set the Interval object
         * 
         * @param intervalSecond 
         */
        void setCreationInterval(double intervalSecond);

        /**
         * @brief Get the Timer object
         *
         * @return Timer&
         */
        Timer &getTimer();

        /**
         * @brief Get the Timer object
         * 
         * @return Timer& 
         */
        Timer &getCreationTimer();
        bool operator==(PlayerController &other);
            
        /**
         * @brief Get the movementsKeys map
         * 
         * @return a map of the playerMovementKeys 
         */
        const std::map<ecs::actions::Action, ecs::input::Key> &getMovementKeys(void) const;

        /**
         * @brief Set the movementsKeys map
         * 
         * @param newPlayerMovementKeys
         */
        void setMovementKeys(std::map<ecs::actions::Action, ecs::input::Key> &newPlayerMovementKeys);

    private:
        Timer _timer;
        double _creationInterval;
        Timer _creationTimer;
        bool _isPlayerOne;
        std::map<ecs::actions::Action, ecs::input::Key> _movementKeys;
    };
}

#endif //PLAYERCONTROLLER_HPP