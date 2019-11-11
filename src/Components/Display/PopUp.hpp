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
        void setId(unsigned int id);
        unsigned int getId(void);

    private:
        unsigned int id;
    };
}

#endif //POPUP_HPP