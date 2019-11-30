//
// Created by Hugo on 11/29/2019.
//

#include "UDPServer.hpp"

ecs::network::UDPServer::UDPServer(const std::string &port) : AUDPNetwork(port)
{
}

void ecs::network::UDPServer::handle_receive(boost::system::error_code ec,
    std::size_t bytes_recvd)
{
    if (!ec && bytes_recvd > 0) {
        if (_sessions.find(sender_endpoint_) != _sessions.end()) {
            _sessions[sender_endpoint_]->manage_data(data_);
        } else {
            _sessions[sender_endpoint_] = std::make_shared<ServerSession>(
                _socket, sender_endpoint_);
            _sessions[sender_endpoint_]->manage_data(data_);
            std::cout << "sessions size : " << _sessions.size() << std::endl;
        }
    } else {
        std::cerr << "error : " << ec << "\t" << bytes_recvd << " bytes sent"
            << std::endl;
    }
    do_receive();
}
