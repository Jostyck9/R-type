/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** ServerSession.hpp
*/

#ifndef SESSION_HPP__
#define SESSION_HPP__

#include "ISession.hpp"

namespace ecs::network {
    class ServerSession
        : public std::enable_shared_from_this<ServerSession>,
            public ecs::network::ISession {
        private:
        udp::endpoint &_sender_endpoint;
        udp::socket &_socket;

        enum {
            max_length = 1024
        };
        size_t recv;

        public:
        ServerSession(udp::socket &_socket, udp::endpoint &senderEndpoint);

        ~ServerSession();

        void do_write(const char data[max_length]) override;

        void handle_write(boost::system::error_code ec, std::size_t length) override;

        void manage_data(const char rawData[max_length]) override;
    };
}
#endif //SESSION_HPP__