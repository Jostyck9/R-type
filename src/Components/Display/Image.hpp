/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Image.hpp
*/

#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <typeindex>
#include "UserInterface.hpp"

namespace components
{
    /**
     * @brief Image describes an attribute that is an Image. 
     *
     */
    class Image : public UserInterface

    {
    public:
        Image() = default;
        virtual ~Image() = 0;
        void setId(unsigned int id);
        unsigned int getId(void);

    private:
        unsigned int id;
    };
}

#endif //IMAGE_HPP