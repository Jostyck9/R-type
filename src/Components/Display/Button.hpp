/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Button.hpp
*/

#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <typeindex>
#include "IUserInterface.hpp"

namespace ecs::components
{
    /**
     * @brief Button describes an attribute that is button. 
     *
     */
    class Button : public IUserInterface

    {
    public:
        Button();        
        Button(const Button &oldButton); 
        ~Button();
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
        bool operator==(Button &other);

    private:
        unsigned int _id;
    };
}

#endif //BUTTON_HPP