//
// Created by Hugo on 11/28/2019.
//

#include <memory>
#include <iostream>
#include <boost/bind.hpp>
#include <ClientSession.hpp>
#include "UDPClient.hpp"

ecs::network::UDPClient::UDPClient(const std::string &ip, const std::string &port) : AUDPNetwork(ip, port),
                                                                                     _resolver(_ioContext),
                                                                                     _endpoints(_resolver.resolve(boost::asio::ip::udp::v4(), ip, port)),
                                                                                     _clientSession()
{
    _clientSession = std::make_shared<ClientSession>(_socket, _endpoints);
}

void ecs::network::UDPClient::handle_receive(boost::system::error_code ec,
                                             std::size_t bytes_recvd)
{
    if (!ec)
    {
        _clientSession->manage_data(data_);
    }
    else
    {
        std::cerr << "error : " << ec << "\t" << bytes_recvd << " bytes sent"
                  << std::endl;
    }
    do_receive();
}

void ecs::network::UDPClient::send(const ecs::network::PacketManager &packet,
                                   const size_t &id)
{
    (void)id;
    _clientSession->manage_data(packet.packet.rawData);
}
