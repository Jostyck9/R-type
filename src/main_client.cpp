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
#include <Client/ClientUdpNetwork.hpp>

enum {
    max_length = 1024
};

int main(int argc, char *argv[])
{
    
    try {
        if (argc != 3) {
            std::cerr << "Usage: blocking_udp_echo_client <host> <port>\n";
            return 1;
        }

        boost::asio::io_context io_context;

        boost::asio::ip::udp::socket s(io_context,
            boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), 0));

        boost::asio::ip::udp::resolver resolver(io_context);

        boost::asio::ip::udp::resolver::results_type endpoints = resolver.resolve(
            boost::asio::ip::udp::v4(), argv[1], argv[2]);

        ecs::network::PacketManager packet;
        packet.setCmd(ecs::network::PacketManager::HANDSHAKE);

        s.send_to(boost::asio::buffer(packet.getRawData(), ecs::network::PacketManager::MAX_LENGTH),
            *endpoints.begin());

        char reply[max_length];
        boost::asio::ip::udp::endpoint sender_endpoint;

        ecs::network::PacketManager packetReceived;


        size_t reply_length = s.receive_from(
            boost::asio::buffer(packetReceived.packet.rawData, max_length), sender_endpoint);
        for (size_t i = 0; i < max_length; i++)
        {
            printf("%02X ", packetReceived.packet.rawData[i]);
        }
        std::cout << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }
    return 0;
}