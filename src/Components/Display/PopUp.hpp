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
        PopUp();
        ~PopUp();
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
        const unsigned int getId(void) const;
        const bool operator==(PopUp &other);
    private:
        unsigned int _id;
    };
}

#endif //POPUP_HPP