//
// Created by Hugo on 11/29/2019.
//

#ifndef R_TYPE_UDPSERVER_HPP
#define R_TYPE_UDPSERVER_HPP

#include <ServerSession.hpp>

#include <AUDPNetwork.hpp>

namespace ecs::network {
    class UDPServer : public AUDPNetwork {
        private:
        std::map<udp::endpoint, std::shared_ptr<ISession>> _sessions;
        public:
        explicit UDPServer(const std::string &port);

        void handle_receive(boost::system::error_code ec,
            std::size_t bytes_recvd) override;
    };
}
#endif //R_TYPE_UDPSERVER_HPP
