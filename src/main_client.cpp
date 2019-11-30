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
#include <RTypeExceptions.hpp>
#include "Rtype.hpp"

int main(int ac, char **av)
{

    try {

        if (ac != 3) {
            std::cerr << "Usage: " << av[0] << " <host> <port>\n";
            return 1;
        }
        Rtype rtype;
        ecs::network::UDPClient clientNetwork(av[1], av[2]);
        ecs::network::PacketManager packet;
        packet.setCmd(ecs::network::PacketManager::HANDSHAKE);
        // std::thread network([&]() {
        //     clientNetwork.run();
        // });
        clientNetwork.send(packet);

        packet.setCmd(ecs::network::PacketManager::ISALIVE);
        rtype.start();

    } catch (const RTypeExceptions &e) {
        std::cerr << e.what() << std::endl;
        std::cerr << "In file: " << e.where() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what();
    }
    return 0;
}