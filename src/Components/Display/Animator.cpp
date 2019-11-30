/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Animator.cpp
*/

#include "Animator.hpp"

namespace ecs::components
{

Animator::Animator(Rect &rect, int maxRep) : _rect(rect), _maxRep(maxRep), _currentRep(0)
{
}

Animator::Animator(const Animator &oldAnimator)
{
    this->_id = oldAnimator.getId();
    this->_rect = oldAnimator.getRect();
    this->_maxRep = oldAnimator.getMaxRep();
}

Animator::~Animator()
{
}

void Animator::setId(const unsigned int &newId)
{
    this->_id = newId;
    return;
}

unsigned int Animator::getId(void) const
{
    return this->_id;
}

const std::type_index Animator::getType() const
{
    return (std::type_index(typeid(Animator)));
}

bool Animator::operator==(Animator &other)
{
    if (other.getId() == this->_id)
        return true;
    return false;
}

const ecs::Rect &Animator::getRect() const
{
    return _rect;
}

const int &Animator::getMaxRep() const
{
    return _maxRep;
}

const int &Animator::getCurrentRep() const
{
    return _currentRep;
}

void Animator::setCurrentRep(int currentRep)
{
    _currentRep = currentRep;
}
} // namespace ecs::components