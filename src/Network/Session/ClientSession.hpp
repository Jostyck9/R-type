//
// Created by Hugo on 11/30/2019.
//

#ifndef R_TYPE_CLIENTSESSION_HPP
#define R_TYPE_CLIENTSESSION_HPP

#include "ISession.hpp"

namespace ecs::network {
    class ClientSession : public  std::enable_shared_from_this<ClientSession>,
        public ecs::network::ISession {
        private:
        udp::socket &_socket;
        boost::asio::ip::udp::resolver::results_type _endpoints;

        enum {
            max_length = 1024
        };
        size_t recv;


        public:

        ClientSession(udp::socket &socket, boost::asio::ip::udp::resolver::results_type &_endpoints);

        virtual ~ClientSession();

        void do_write(char data[max_length]);

        void handle_write(boost::system::error_code ec, std::size_t length);

        void manage_data(char rawData[max_length]) override;

    };
}

#endif //R_TYPE_CLIENTSESSION_HPP
