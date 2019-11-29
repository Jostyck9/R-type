//
// Created by Hugo on 11/28/2019.
//

#ifndef R_TYPE_CLIENTUDPNETWORK_HPP
#define R_TYPE_CLIENTUDPNETWORK_HPP

#include <boost/asio.hpp>
#include <vector>
#include "PacketManager.hpp"

namespace ecs {
    namespace network {
        class ClientUDPNetwork : public std::enable_shared_from_this<ClientUDPNetwork> {
            private:
            boost::asio::io_context _ioContext;

            boost::asio::ip::udp::socket _socket;

            boost::asio::ip::udp::resolver _resolver;
            
            boost::asio::ip::udp::resolver::results_type _endpoints;

            boost::asio::ip::udp::endpoint _senderEndpoint;
            std::string _host;
            std::string _port;

            public:

            ClientUDPNetwork(const std::string &host, const std::string &port);

            virtual ~ClientUDPNetwork();

            void receiveHandler(const std::error_code &error,
                std::size_t bytesTransferred
            );

            void sendHandler(const std::error_code& error,
                std::size_t bytesTransferred);
            void addPacket(const ecs::network::PacketManager &);
            void receive();
            void send(const ecs::network::PacketManager& packet);
            void run();
        };
    }
};

#endif //R_TYPE_CLIENTUDPNETWORK_HPP
