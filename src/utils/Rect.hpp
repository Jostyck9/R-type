/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Rect.hpp
*/

#ifndef RECT_HPP__
#define RECT_HPP__

namespace ecs
{
class Rect
{
private:
    int _width;
    int _height;
    int _posX;
    int _posY;

public:
    Rect(int width = 0, int height = 0, int posX = 0, int posY = 0);
    Rect (const Rect &oldRect);
    ~Rect();
    int getWidth() const;
    int getHeight() const;
    int getPosX() const;
    int getPosY()const;
    bool operator==(const Rect &other) const;

};
} // namespace ecs

#endif