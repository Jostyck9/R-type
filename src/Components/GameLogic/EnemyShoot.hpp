/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** EnemyShoot.hpp
*/

#ifndef ENEMYSHOOT_HHP
#define ENEMYSHOOT_HHP

#include <typeindex>
#include "IGameLogic.hpp"
#include "Timer.hpp"

namespace ecs::components
{
    /**
     * @brief Damage describes an attribute that stores a numeric value representing Damage points. 
     *
     */
    class EnemyShoot : public IGameLogic
    {
    public:
        EnemyShoot();
        EnemyShoot(bool canShoot, double endTime = 0);
        EnemyShoot(const EnemyShoot &oldDamage);
        ~EnemyShoot();
        void setCanShoot(const bool &newValue);
        bool getCanShoot(void) const;
        /**
         * @brief Get the Type object
         * 
         * @return const std::type_index 
         */
        const std::type_index getType() const;

        /**
         * @brief Get the bullet Timer object
         *
         * @return Timer&
         */
        Timer &getBulletTimer();

        /**
         * @brief Get the end time object
         *
         * @return double
         */
        double getEndTime();
        bool operator==(EnemyShoot &other);
    private:
        Timer _timerBullet;
        double _endTime;
        bool _canShoot;
    };
}

#endif //ENEMYSHOOT_HHP