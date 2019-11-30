//
// Created by Hugo on 11/28/2019.
//

#ifndef R_TYPE_UDPCLIENT_HPP
#define R_TYPE_UDPCLIENT_HPP

#include <boost/asio.hpp>
#include <vector>
#include <AUDPNetwork.hpp>
#include <ISession.hpp>
#include "PacketManager.hpp"

namespace ecs::network {

    class UDPClient : public AUDPNetwork {
        private:
        boost::asio::ip::udp::resolver _resolver;

        boost::asio::ip::udp::resolver::results_type _endpoints;

        std::shared_ptr<ISession> _clientSession;
        public:
        UDPClient(const std::string &ip, const std::string &port);

        void handle_receive(boost::system::error_code ec,
            std::size_t bytes_recvd
        ) override;
    };

}

#endif //R_TYPE_UDPCLIENT_HPP
