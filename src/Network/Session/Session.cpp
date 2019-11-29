/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Session.cpp
*/

#include <iostream>
#include <memory>
#include "Session.hpp"

Session::Session(udp::socket &socket, udp::endpoint &senderEndpoint) : _sender_endpoint(senderEndpoint), _socket(socket)
{
}

Session::~Session()
{
}

void Session::do_write(char rawData[max_length])
{
    std::cout << "Ok here" << std::endl;
    _socket.async_send_to(
        boost::asio::buffer(rawData, max_length), _sender_endpoint,
        std::bind(&Session::handle_write, shared_from_this(), std::placeholders::_1,
            std::placeholders::_2));
        // std::bind(&Session::handle_write, shared_from_this(), std::placeholders::_1, std::placeholders::_2));
}

void Session::handle_write(boost::system::error_code ec, std::size_t length)
{
    if (!ec)
    {
        std::cout << length << " bytes sent" << std::endl;
    }
}

void Session::manage_data(char rawData[max_length])
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