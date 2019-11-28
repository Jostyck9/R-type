//
// Created by Hugo on 11/28/2019.
//

#include <iostream>
#include "ClientUdpNetwork.hpp"

ClientUDPNetwork::ClientUDPNetwork(const std::string &host, unsigned short port)
    : _host(host), _port(port), _resolver(_ioContext), _socket(_ioContext,
    boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), 0)), _endpoints(
    _resolver.resolve(boost::asio::ip::udp::v4(), host, std::to_string(port)))
{
}

void ClientUDPNetwork::run()
{
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

void ClientUDPNetwork::receiveHandler(const std::error_code &error,
    size_t bTr)
{
    if (!error) {

    } else {
        std::cerr << "error receiving\n";
    }

}

void ClientUDPNetwork::receive()
{
}

void ClientUDPNetwork::send()
{
}

ClientUDPNetwork::~ClientUDPNetwork() = default;
