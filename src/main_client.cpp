/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** main_client.cpp
*/

#include <iostream>
#include <cmath>
#include "RTypeExceptions.hpp"
#include "Rtype.hpp"
#include "Timer.hpp"

int main()
{
    try {
        Rtype rtype;

        rtype.start();
        rtype.stop();

        /*Timer timer(5000);
        timer.start();
        while(!timer.checkEndTimer()) {}
        timer.stop();

        std::cout << "Seconds: " << timer.getElapsedSeconds() << std::endl;
        std::cout << "Milliseconds: " << timer.getElapsedMilliseconds() << std::endl;*/

    } catch (const RTypeExceptions &e) {
        std::cerr << e.what() << std::endl;
        std::cerr << "In file: " << e.where() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what();
    }
    return 0;
}
