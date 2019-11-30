/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Parallax.cpp
*/

#include "Parallax.hpp"
#include "Rect.hpp"

namespace ecs::components
{

Parallax::Parallax(double intervalSecond, int move, int offset, Rect &origin) : _interval(intervalSecond), _move(move), _offset(offset), _origin(origin)
{
    _timer.start();
}

Parallax::Parallax(const Parallax &oldParallax)
{
    this->_id = oldParallax.getId();
    this->_move = oldParallax.getMove();
    this->_offset = oldParallax.getOffset();
    this->_interval = oldParallax.getInterval();
}

Parallax::~Parallax()
{
}

const ecs::Rect &Parallax::getRect() const
{
    return _origin;
}


void Parallax::setId(const unsigned int &newId)
{
    this->_id = newId;
    return;
}

unsigned int Parallax::getId(void) const
{
    return this->_id;
}

const std::type_index Parallax::getType() const
{
    return (std::type_index(typeid(Parallax)));
}

bool Parallax::operator==(Parallax &other)
{
    if (other.getId() == this->_id)
        return true;
    return false;
}

Timer &Parallax::getTimer()
{
    return _timer;
}

void Parallax::setMove(int &move)
{
    _move = move;
}

int Parallax::getMove() const
{
    return _move;
}

double Parallax::getInterval() const
{
    return _interval;
}

void Parallax::setInterval(double intervalSecond)
{
    _interval = intervalSecond;
}

void Parallax::setOffset(int &offset)
{
    _offset = offset;
}

int Parallax::getOffset() const
{
    return _offset;
}
} // namespace ecs::components