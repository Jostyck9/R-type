/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Position.cpp
*/

#include "Position.hpp"

namespace ecs::components
{
    bool Position::operator==(Position const &other) const
    {
        if (_x == other.getX() && _y == other.getY())
            return true;
        return false;
    }

    Position::Position(float x, float y) : _x(x), _y(y)
    {
    }
    
    Position::~Position()
    {
    }
    
    float Position::getX() const
    {
        return _x;
    }

    float Position::getY() const
    {
        return _y;
    }

    const std::pair<float, float> Position::getPosition() const
    {
        return std::make_pair(_x, _y);
    }

    void Position::setX(float x)
    {
        _x = x;
    }

    void Position::serY(float y)
    {
        _y = y;
    }

    void Position::setPosition(const std::pair<float, float> position)
    {
        _x = position.first;
        _y = position.second;
    }

    const std::type_index Position::getType() const
    {
        return (std::type_index(typeid(Position)));
    }
}