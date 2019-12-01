/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** EnemiesController.hpp
*/

#ifndef ENEMIESCONTROLLER_HPP
#define ENEMIESCONTROLLER_HPP

#include <typeindex>
#include <string>
#include "Timer.hpp"
#include "IGameLogic.hpp"

namespace ecs::components
{
    /**
     * @brief EnemiesController is used to recognize player entity
     *
     */
    class EnemiesController : public IGameLogic
    {
    public:
        EnemiesController();
        EnemiesController(const std::string &type);
        EnemiesController(const EnemiesController &oldEnemiesController);
        ~EnemiesController() = default;
        /**
         * @brief Get the Type object
         * 
         * @return const std::type_index 
         */
        const std::type_index getType() const override;
        std::string getShipType(void) const;
        void setShipType(const std::string &type);
        bool operator==(EnemiesController &other);
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
         * @brief Get the Timer object
         * 
         * @return Timer& 
         */
        Timer &getTimer();

    private:
        std::string _shipType;
        double _interval;
        Timer _timer;
    };
}

#endif //EnemiesCONTROLLER_HPP