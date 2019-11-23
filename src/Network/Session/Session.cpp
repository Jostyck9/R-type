/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Session.cpp
*/

#include <iostream>
#include <memory>
#include "Session.hpp"

Session::Session(boost::asio::io_context &io_context, boost::asio::ip::udp::endpoint &senderEndpoint) : _io_context(io_context), _socket(io_context), _sender_endpoint(senderEndpoint)
{
}

Session::~Session()
{
}

void Session::do_read()
{
    _socket.async_receive_from(boost::asio::buffer(rawData, max_length),
                            std::bind(&Session::handle_read, shared_from_this(), std::placeholders::_1, std::placeholders::_2));
    // boost::asio::async_read(_socket, boost::asio::buffer(rawData),
    //                         std::bind(&Session::handle_read, shared_from_this(), std::placeholders::_1, std::placeholders::_2));
}

void Session::handle_read(boost::system::error_code ec, std::size_t length)
{
    if (ec)
    {
        std::cerr << "error : " << ec.category().name() << " : " << ec.value() << " : " << ec.message() << std::endl;
    }
    std::cout << length << " bytes received" << std::endl;
    do_write();
}

void Session::do_write()
{
    boost::asio::async_write(_socket, boost::asio::buffer(rawData),
                             std::bind(&Session::handle_write, shared_from_this(), std::placeholders::_1, std::placeholders::_2));
}

void Session::handle_write(boost::system::error_code ec, std::size_t length)
{
    if (!ec)
    {
        std::cout << length << " bytes sent" << std::endl;
    }
}

bool Session::start()
{
    do_read();
    return false;
}

bool Session::stop()
{
    return true;
}
boost::asio::ip::udp::socket &Session::getSocket()
{
    return _socket;
}
