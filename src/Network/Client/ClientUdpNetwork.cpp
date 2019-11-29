//
// Created by Hugo on 11/28/2019.
//

#include <memory>
#include <iostream>
#include <boost/bind.hpp>
#include "ClientUDPNetwork.hpp"

ecs::network::ClientUDPNetwork::ClientUDPNetwork(const std::string &host,
    const std::string &port
) : _host(host),
_port(port), 
_socket(_ioContext, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), 0)),
_resolver(_ioContext),
_endpoints(_resolver.resolve(boost::asio::ip::udp::v4(), host, port))
{
    ecs::network::PacketManager packet;
    packet.setCmd(ecs::network::PacketManager::HANDSHAKE);
    this->send(packet);
}

void ecs::network::ClientUDPNetwork::run()
{
    receive();
    while (!_ioContext.stopped()) {
        try {
            _ioContext.run();
        } catch (const std::exception &e) {
            std::cerr << "Client: network exception: " << e.what() << std::endl;
        } catch (...) {
            std::cerr << "Unknown exception in client network" << std::endl;
        }
    }
}

void ecs::network::ClientUDPNetwork::receiveHandler(
    const std::error_code &error, size_t bTr
)
{
    if (!error) {
    } else {
        std::cerr << "error receiving\n";
    }
    receive();
}

void ecs::network::ClientUDPNetwork::receive()
{
    ecs::network::PacketManager packetReceived;
    
    _socket.async_receive_from(boost::asio::buffer(packetReceived.packet.rawData, ecs::network::PacketManager::MAX_LENGTH), _senderEndpoint,
        std::bind(&ClientUDPNetwork::receiveHandler, shared_from_this(), std::placeholders::_1, std::placeholders::_2));
    /*
    _socket.async_receive_from(boost::asio::buffer(_packetReceived),
        _senderEndpoint, [this](std::error_code ec, std::size_t bytes_recvd) {
            this->receiveHandler(ec, bytes_recvd);
        });
        */
}

void ecs::network::ClientUDPNetwork::send(const ecs::network::PacketManager &packet)
{
    _socket.async_send_to(boost::asio::buffer(packet.getRawData(),
        ecs::network::PacketManager::MAX_LENGTH), *_endpoints.begin(),
        boost::bind(&ClientUDPNetwork::sendHandler, shared_from_this(), boost::asio::placeholders::error,
            boost::asio::placeholders::bytes_transferred));
}

void ecs::network::ClientUDPNetwork::sendHandler(const std::error_code& error, std::size_t bytesTransferred)
{
    if (!error)
    {
        std::cout << bytesTransferred << " bytes sent" << std::endl;
    }
}

void ecs::network::ClientUDPNetwork::addPacket(
    const ecs::network::PacketManager &packet
)
{
 
}

ecs::network::ClientUDPNetwork::~ClientUDPNetwork() = default;
