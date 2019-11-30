/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** ServerSession.cpp
*/

#include <iostream>
#include <memory>
#include "ServerSession.hpp"

ecs::network::ServerSession::ServerSession(udp::socket &socket,
    udp::endpoint &senderEndpoint
) : _sender_endpoint(senderEndpoint), _socket(socket)
{
}

ecs::network::ServerSession::~ServerSession()
{
}

void ecs::network::ServerSession::do_write(char rawData[max_length])
{
    _socket.async_send_to(boost::asio::buffer(rawData, max_length),
        _sender_endpoint, std::bind(&ecs::network::ServerSession::handle_write,
            shared_from_this(), std::placeholders::_1, std::placeholders::_2));
}

void ecs::network::ServerSession::handle_write(boost::system::error_code ec,
    std::size_t length
)
{
    //TODO Here PROTOCOLE
    if (ec) {
        std::cerr << "error : " << ec << "\t" << length << " bytes sent"
            << std::endl;
    }
}

void ecs::network::ServerSession::manage_data(char rawData[max_length])
{
    std::cout << "sent from :" << _sender_endpoint.address().to_string() << std::endl;
    std::cout << "received : " << std::endl;
    for (size_t i = 0; i < max_length; i++)
    {
        printf("%02X ", rawData[i]);
    }
    std::cout << std::endl;
    do_write(rawData);
}