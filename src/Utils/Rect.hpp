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
    /**
     * @brief Get the Width object
     * 
     * @return int 
     */
    int getWidth() const;
    /**
     * @brief Get the Height object
     * 
     * @return int 
     */
    int getHeight() const;
    /**
     * @brief Get the Pos X object
     * 
     * @return int 
     */
    int getPosX() const;
    /**
     * @brief Get the Pos Y object
     * 
     * @return int 
     */
    int getPosY()const;
    /**
     * @brief Set the Width object
     * 
     * @param width 
     */
    void setWidth(int width);
    /**
     * @brief Set the Height object
     * 
     * @param height 
     */
    void setHeight(int height);
    /**
     * @brief Set the Pos X object
     * 
     * @param posX 
     */
    void setPosX(int posX);
    /**
     * @brief Set the Pos Y object
     * 
     * 
     * @param posY 
     */
    void setPosY(int posY);
    bool operator==(const Rect &other) const;

};
} // namespace ecs

#endif