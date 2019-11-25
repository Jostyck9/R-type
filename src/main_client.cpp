/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** main_client.cpp
*/

#include <iostream>
#include "RTypeExceptions.hpp"
#include "Rtype.hpp"

int main()
{
    try {
        Rtype rtype;

        rtype.start();
        rtype.stop();
    } catch (const RTypeExceptions &e) {
        std::cerr << e.what() << std::endl;
        std::cerr << "In file: " << e.where() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what();
    }
    return 0;
}
