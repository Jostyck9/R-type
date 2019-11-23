/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Image.hpp
*/

#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <typeindex>
#include "IUserInterface.hpp"

namespace ecs::components
{
    /**
     * @brief Image describes an attribute that is an Image. 
     *
     */
    class Image : public IUserInterface

    {
    public:
        Image();        
        Image(const Image &oldImage); 
        ~Image();
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

        bool operator==(Image &other);
    private:
        unsigned int _id;
    };
}

#endif //IMAGE_HPP