/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Text.hpp
*/

#ifndef TEXT_HPP
#define TEXT_HPP

#include <typeindex>
#include <string>
#include <Color.hpp>
#include "IUserInterface.hpp"

namespace ecs::components
{
/**
     * @brief Text describes an attribute that is a Text. 
     *
     */
class Text : public IUserInterface

{
public:
    Text();
    Text(const std::string &str, int size, float posX = 0, float posY = 0);
    Text(const Text &oldText);
    ~Text();
    /**
         * @brief Set new value to the component id
         * 
         * @param newId 
         */
    void setId(const unsigned int &newId);
    /**
         * @brief return the component id
         * 
         */
    unsigned int getId(void) const;
    /**
         * @brief Get the Type object
         * 
         * @return const std::type_index 
         */
    const std::type_index getType() const;
    /**
         * @brief Set new value to the comp string
         * 
         * @param newstr 
         */
    void setStr(const std::string &newstr);
    /**
         * @brief return the component string
         * 
         */
    std::string getStr(void) const;
    /**
         * @brief Set new value to the component size
         * 
         * @param newSize
         */
    void setSize(const int &newSize);
    /**
         * @brief return the component size
         * 
         */
    int getSize(void) const;
    /**
         * @brief Set new value to the color
         *
         * @param newColor
         */
    void setColor(const ecs::Color &newcolor);
    /**
         * @brief return the color
         *
         */
    ecs::Color getColor(void) const;

     /**
      * @brief Get the Postion object
      * 
      * @return const std::pair<float, float> 
      */
     const std::pair<float, float> &getPostion() const;

     /**
      * @brief Set the Postion object
      * 
      * @param pos 
      */
     void setPostion(const std::pair<float, float> &pos);

     bool operator==(Text &other);

private:
    unsigned int _id;
    std::string _string;
    int _size;
    ecs::Color _color;
    std::pair<float, float> _pos;
};
} // namespace ecs::components

#endif //TEXT_HPP