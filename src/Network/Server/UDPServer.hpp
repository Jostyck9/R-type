//
// Created by Hugo on 11/29/2019.
//

#ifndef R_TYPE_UDPSERVER_HPP
#define R_TYPE_UDPSERVER_HPP

#include <ServerSession.hpp>
#include "ServerExceptions.hpp"
#include <AUDPNetwork.hpp>
#include <Room/RoomManager.hpp>

namespace ecs::network {
    class UDPServer : public AUDPNetwork {
        private:

        size_t _sessionId;
        std::map<std::pair<size_t, udp::endpoint>, std::shared_ptr<ISession>> _sessions;

        RoomManager _roomManager;
        public:
        explicit UDPServer(const std::string &port);

        void handle_receive(boost::system::error_code ec,
            std::size_t bytes_recvd) override;

        /**
         * @brief Get the Session object
         * 
         * @param id 
         * @return std::shared_ptr<ISession>& 
         */
        std::shared_ptr<ISession> &getSession(const size_t &id);
        /**
         * @brief Get the Session object
         * 
         * @param endpoint 
         * @return std::shared_ptr<ISession>& 
         */
        std::shared_ptr<ISession> &getSession(const udp::endpoint &endpoint);

        void send(const ecs::network::PacketManager &packet, const size_t &id
        ) override;
    };
}
#endif //R_TYPE_UDPSERVER_HPP
