/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** EnemyShoot.cpp
*/

#include "EnemyShoot.hpp"

ecs::components::EnemyShoot::EnemyShoot() : _canShoot(false), _timerBullet()
{
    _timerBullet.start();
    _endTime = 0;
}

ecs::components::EnemyShoot::EnemyShoot(bool canShoot, double endTime) : _canShoot(canShoot), _timerBullet(endTime)
{
    _endTime = endTime;
    _timerBullet.start();
}

ecs::components::EnemyShoot::EnemyShoot(const EnemyShoot &oldDamage)
{
    this->_canShoot = oldDamage.getCanShoot();
}

ecs::components::EnemyShoot::~EnemyShoot()
{
}

void ecs::components::EnemyShoot::setCanShoot(const bool &newValue)
{
    this->_canShoot = newValue;
}

bool ecs::components::EnemyShoot::getCanShoot(void) const
{
    return(this->_canShoot);
}

const std::type_index ecs::components::EnemyShoot::getType() const
{
    return (std::type_index(typeid(EnemyShoot)));
}

ecs::components::Timer &ecs::components::EnemyShoot::getBulletTimer()
{
    return _timerBullet;
}

double ecs::components::EnemyShoot::getEndTime()
{
    return _endTime;
}

bool ecs::components::EnemyShoot::operator==(EnemyShoot &other)
{
    return other.getCanShoot() == this->_canShoot;
}