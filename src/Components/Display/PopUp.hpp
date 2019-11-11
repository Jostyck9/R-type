/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** PopUp.hpp
*/

#ifndef POPUP_HPP
#define POPUP_HPP

#include <typeindex>
#include "UserInterface.hpp"

namespace components
{
    /**
     * @brief PopUp describes an attribute that is a popUp. 
     *
     */
    class PopUp : public UserInterface

    {
    public:
        PopUp() = default;
        virtual ~PopUp() = 0;
        void setId(const unsigned int newId);
        const unsigned int getId(void) const;

    private:
        unsigned int _id;
    };
}

#endif //POPUP_HPP