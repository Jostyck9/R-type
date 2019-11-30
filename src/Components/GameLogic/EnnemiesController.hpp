/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** EnnemiesController.hpp
*/

#ifndef ENNEMIESCONTROLLER_HPP
#define ENNEMIESCONTROLLER_HPP

#include <typeindex>
#include <string>
#include "Timer.hpp"
#include "IGameLogic.hpp"

namespace ecs::components
{
    /**
     * @brief EnnemiesController is used to recognize player entity
     *
     */
    class EnnemiesController : public IGameLogic
    {
    public:
        EnnemiesController();
        EnnemiesController(const std::string &type);
        EnnemiesController(const EnnemiesController &oldEnnemiesController);
        ~EnnemiesController() = default;
        /**
         * @brief Get the Type object
         * 
         * @return const std::type_index 
         */
        const std::type_index getType() const override;
        std::string getShipType(void) const;
        void setShipType(const std::string &type);
        bool operator==(EnnemiesController &other);
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

#endif //ENNEMIESCONTROLLER_HPP