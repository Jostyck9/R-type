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
    Rect(int width, int height, int posX, int posY);
    Rect (const Rect &oldRect);
    ~Rect();
    int getWidth();
    int getHeight();
    int getPosX();
    int getPosY();
    bool operator==(Rect &other);

};
} // namespace ecs

#endif