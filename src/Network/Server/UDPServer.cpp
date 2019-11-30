//
// Created by Hugo on 11/29/2019.
//

#include "UDPServer.hpp"

ecs::network::UDPServer::UDPServer(const std::string &port) : _sessionId(0),
    AUDPNetwork(port)
{
}

void ecs::network::UDPServer::handle_receive(boost::system::error_code ec,
    std::size_t bytes_recvd
)
{
    if (!ec && bytes_recvd > 0) {
        try {
            auto session = getSession(sender_endpoint_);
            session->manage_data(data_);
        } catch (const ServerExceptions &se) {
            (void)se;
            _sessions.emplace(
                std::make_pair(std::make_pair(++_sessionId, sender_endpoint_),
                    std::make_shared<ServerSession>(_socket,
                        sender_endpoint_)));
            getSession(sender_endpoint_)->manage_data(data_);
            std::cout << "sessions size : " << _sessions.size() << std::endl;
        }
    } else {
        std::cerr << "error : " << ec << "\t" << bytes_recvd << " bytes sent"
            << std::endl;
    }
    do_receive();
}

std::shared_ptr<ecs::network::ISession> &ecs::network::UDPServer::getSession(
    const size_t &id
)
{
    for (auto &session : _sessions) {
        if (id == session.first.first)
            return session.second;
    }
    throw ServerExceptions("Invalid session id", "UDPServer getSession");
}

std::shared_ptr<ecs::network::ISession> &ecs::network::UDPServer::getSession(
    const udp::endpoint &endpoint
)
{
    for (auto &session : _sessions) {
        if (endpoint == session.first.second)
            return session.second;
    }
    throw ServerExceptions("Unknown sender endpoint", "UDPServer getSession");
}

void ecs::network::UDPServer::send(const ecs::network::PacketManager &packet,
    const size_t &id
)
{
    getSession(id)->manage_data(packet.packet.rawData);
}
