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
        Image();
        ~Image();
        void setId(const unsigned int &newId);
        const unsigned int getId(void) const;

    private:
        unsigned int _id;
    };
}

#endif //IMAGE_HPP