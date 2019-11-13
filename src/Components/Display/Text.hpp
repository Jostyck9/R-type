/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Text.hpp
*/

#ifndef TEXT_HPP
#define TEXT_HPP

#include <typeindex>
#include "IUserInterface.hpp"

namespace components
{
    /**
     * @brief Text describes an attribute that is a Text. 
     *
     */
    class Text : public IUserInterface

    {
    public:
        Text();
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
        bool operator==(Text &other);

    private:
        unsigned int _id;
    };
}

#endif //TEXT_HPP