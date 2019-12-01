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
    private:
        Timer _timer;
        double _creationInterval;
        Timer _creationTimer;
    };
}

#endif //PLAYERCONTROLLER_HPP