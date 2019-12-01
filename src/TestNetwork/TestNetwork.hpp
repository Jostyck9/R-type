/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** TestNetwork.hpp
*/

#ifndef TESTNETWORK_HPP_
#define TESTNETWORK_HPP_

#include <memory>
#include <boost/asio.hpp>
#include "PacketManager.hpp"

using boost::asio::ip::udp;

class TestNetwork : public std::enable_shared_from_this<TestNetwork>
{
private:
    boost::asio::io_context _ioContext;
    udp::socket _socket;
    udp::resolver _resolver;
    udp::resolver::results_type _endpoints;
    udp::endpoint sender_endpoint_;
    ecs::network::PacketManager _ecs_packet;

    std::string _ip;
    std::string _port;
    enum
    {
        max_length = 1024
    };
    char data_[max_length];

public:
    TestNetwork(const std::string &ip, const std::string &port);
    ~TestNetwork();

    void doReceive();
    void handleReceive(boost::system::error_code ec, std::size_t bytes_recvd);
    void doSend();
    void handleSend(boost::system::error_code ec, std::size_t bytes_recvd);
    void start();
};

#endif //TESTNETWORK_HPP_