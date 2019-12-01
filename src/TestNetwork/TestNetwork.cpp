/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** TestNetwork.cpp
*/

#include "TestNetwork.hpp"

TestNetwork::TestNetwork(const std::string &ip, const std::string &port) : _socket(_ioContext, udp::endpoint(udp::v4(), 0)),
                                                                           _resolver(_ioContext),
                                                                           _endpoints(_resolver.resolve(udp::v4(), ip, port)),
                                                                           _ip(ip),
                                                                           _port(port)
{
    memset(data_, 0, max_length);
}

TestNetwork::~TestNetwork()
{
}

void TestNetwork::handleReceive(boost::system::error_code ec, std::size_t bytes_recvd)
{
    if (!ec)
    {
        for (size_t i = 0; i < bytes_recvd; i++)
        {
            printf("%02x ", data_[i]);
        }
        printf("\n");
        doSend();
    }
    else
    {
        printf("Error received\n");
    }
}

void TestNetwork::doReceive()
{
    _socket.async_receive_from(boost::asio::buffer(data_, max_length),
                               sender_endpoint_,
                               std::bind(&TestNetwork::handleReceive, shared_from_this(), std::placeholders::_1, std::placeholders::_2));
}

void TestNetwork::doSend()
{
    _ecs_packet.clear();
    _socket.async_send_to(boost::asio::buffer(_ecs_packet.packet.rawData, ecs::network::PacketManager::MAX_LENGTH),
                          *_endpoints.begin(),
                          std::bind(&TestNetwork::handleSend, shared_from_this(), std::placeholders::_1, std::placeholders::_2));
}

void TestNetwork::handleSend(boost::system::error_code ec, std::size_t bytes_recvd)
{
    if (!ec)
    {
        printf("%u bytes sent\n", bytes_recvd);
        doReceive();
    }
    else
    {
        printf("Error send\n");
    }
}

void TestNetwork::start()
{
    // doSend();
    _ioContext.run();
}
