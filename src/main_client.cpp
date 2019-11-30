/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** main_client.cpp
*/

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <boost/asio.hpp>
#include <Client/UDPClient.hpp>

int main(int ac, char **av)
{

    try {
        if (ac != 3) {
            std::cerr << "Usage: " << av[0] << " <host> <port>\n";
            return 1;
        }

        ecs::network::UDPClient clientNetwork(av[1], av[2]);

        clientNetwork.run();

        ecs::network::PacketManager packet;

        packet.setCmd(ecs::network::PacketManager::HANDSHAKE);

        clientNetwork.send(packet);

    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }
    return 0;
}