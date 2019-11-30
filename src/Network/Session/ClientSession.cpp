//
// Created by Hugo on 11/30/2019.
//

#include <iostream>
#include <PacketManager.hpp>
#include "ClientSession.hpp"

ecs::network::ClientSession::ClientSession(udp::socket &socket,
    boost::asio::ip::basic_resolver<udp, boost::asio::executor>::results_type &endpoints
) : _socket(socket), _endpoints(endpoints)
{
}

ecs::network::ClientSession::~ClientSession()
= default;

void ecs::network::ClientSession::do_write(const char *data)
{
    _socket.async_send_to(boost::asio::buffer(data, max_length),
        *_endpoints.begin(),
        std::bind(&ecs::network::ClientSession::handle_write,
            shared_from_this(), std::placeholders::_1, std::placeholders::_2));
}

void ecs::network::ClientSession::handle_write(boost::system::error_code ec,
    std::size_t length
)
{
    //TODO Here PROTOCOLE
    if (ec) {
        std::cerr << "error : " << ec << "\t" << length << " bytes sent"
            << std::endl;
    }
}

void ecs::network::ClientSession::manage_data(const char *rawData)
{
    std::cout << "Packet received" << std::endl;

    std::memcpy(_packet.packet.rawData, rawData, max_length);

    do_write(rawData);
}

