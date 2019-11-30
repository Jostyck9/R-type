/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** main_server.cpp
*/

#include <cstdlib>
#include <iostream>
#include <boost/asio.hpp>
#include <map>
#include <Server/UDPServer.hpp>
#include <Room/RoomManager.hpp>
#include "ServerSession.hpp"

int main(int ac, char *av[])
{
    try {
        if (ac != 2) {
            std::cerr << "Usage: " << av[0] << " <port>\n";
            return 1;
        }

        RoomManager roomManager(8);
        ecs::network::UDPServer serverNetwork(av[1]);

        std::thread network([&](){serverNetwork.run();});

    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}
