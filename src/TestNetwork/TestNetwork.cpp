/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** TestNetwork.cpp
*/

#include <cstring>
#include "TestNetwork.hpp"

TestNetwork::TestNetwork(const std::string &ip, const std::string &port) : _socket(_ioContext, udp::endpoint(udp::v4(), 0)),
                                                                           _resolver(_ioContext),
                                                                           _endpoints(_resolver.resolve(udp::v4(), ip, port)),
                                                                           _timer(_ioContext),
                                                                           _ip(ip),
                                                                           _port(port)
{
    std::memset(data_, 0, max_length);
}

TestNetwork::~TestNetwork()
{
}

void TestNetwork::manageListRoom()
{
    for (size_t i = 0; i < (size_t)_ecs_packet.getListRooms().size; i++) {
        // _ecs_packet.getListRooms().listRoom[i].
        printf("Room %i :\n", _ecs_packet.getListRooms().listRoom[i].id);
        printf("\topen : %i\n", _ecs_packet.getListRooms().listRoom[i].isOpen);
        printf("\tstarted : %i\n", _ecs_packet.getListRooms().listRoom[i].isStarted);
        printf("\n max players : %i\n", _ecs_packet.getListRooms().listRoom[i].nbPlayerMax);
        printf("\tcurrent players : %i\n", _ecs_packet.getListRooms().listRoom[i].nbPlayers);
        printf("\n");
    }
    doReceive();
}

void TestNetwork::handleReceive(boost::system::error_code ec, std::size_t bytes_recvd)
{
    if (!ec)
    {
        std::memcpy(_ecs_packet.packet.rawData, data_, bytes_recvd);
        if (_ecs_packet.getMagicNumber() != 42) {
            printf("Unknown packet");
            doReceive();
            return;
        }
        if (!_ecs_packet.isSuccessful()) {
            printf("Error : %s\n", _ecs_packet.getMsg().c_str());
            doReceive();
            return;
        }
        if (_ecs_packet.getCmd() == ecs::network::PacketManager::GETROOMS) {
            manageListRoom();
            doReceive();
            return;
        }
        // for (size_t i = 0; i < bytes_recvd; i++)
        // {
        //     printf("%02x ", data_[i]);
        // }
        // printf("\n");
        printf("Check\n");
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
    (void) bytes_recvd;
    if (!ec)
    {
        // printf("%u bytes sent\n", bytes_recvd);
        doReceive();
    }
    else
    {
        printf("Error send\n");
    }
}

void TestNetwork::checkTimeOut()
{
    _timer.expires_after(std::chrono::seconds(5));
    _timer.async_wait(std::bind(&TestNetwork::handleTimeOut, shared_from_this()));
}

void TestNetwork::handleTimeOut()
{
    checkTimeOut();
}

void TestNetwork::askListRoom()
{
    _ecs_packet.clear();
    _ecs_packet.setCmd(ecs::network::PacketManager::GETROOMS);
    doSend();
}

void TestNetwork::start()
{
    // doSend();
    // _timer.expires_after(std::chrono::seconds(5));
    // _timer.async_wait(
    //     [](const boost::system::error_code& /*error*/) {
    //         std::cout << "timeouttyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy" << std::endl;
    //     }
    // );
    checkTimeOut();
    _ioContext.run();
}
