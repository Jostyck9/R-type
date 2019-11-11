/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Output.hpp
*/

#ifndef OUTPUT_HPP
#define OUTPUT_HPP

#include "IIO.hpp"

namespace components
{
    /**
     * @brief Output describes the Output of an Component
     * 
     */
    class Output : public IIO
    {
    private:
    public:
        Output();
        ~Output();
    };
}


#endif