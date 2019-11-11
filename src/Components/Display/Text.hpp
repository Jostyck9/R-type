/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Text.hpp
*/

#ifndef TEXT_HPP
#define TEXT_HPP

#include <typeindex>
#include "UserInterface.hpp"

namespace components
{
    /**
     * @brief Text describes an attribute that is a Text. 
     *
     */
    class Text : public UserInterface

    {
    public:
        Text() = default;
        virtual ~Text() = 0;
        void setId(unsigned int id);
        unsigned int getId(void);

    private:
        unsigned int id;
    };
}

#endif //TEXT_HPP