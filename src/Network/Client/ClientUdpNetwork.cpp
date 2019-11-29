//
// Created by Hugo on 11/28/2019.
//

#include <iostream>
#include "ClientUDPNetwork.hpp"

ecs::network::ClientUDPNetwork::ClientUDPNetwork(const std::string &host,
    const std::string &port
) : _host(host), _port(port), _resolver(_ioContext), _socket(_ioContext,
    boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), 0)), _endpoints(
    *_resolver.resolve(
        boost::asio::ip::udp::resolver::query(boost::asio::ip::udp::v4(), host,
            port)))
{
    this->send();
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
    _socket.async_receive_from(boost::asio::buffer(_packetReceived),
        _senderEndpoint, [this](std::error_code ec, std::size_t bytes_recvd) {
            this->receiveHandler(ec, bytes_recvd);
        });
}

void ecs::network::ClientUDPNetwork::send()
{
    _socket.send_to(boost::asio::buffer(_packetToSend.begin()->getRawData(),
        ecs::network::PacketManager::MAX_LENGTH), _endpoints);
}

void ecs::network::ClientUDPNetwork::addPacket(
    const ecs::network::PacketManager &packet
)
{
    _packetToSend.emplace_back(packet);
}

ecs::network::ClientUDPNetwork::~ClientUDPNetwork() = default;
