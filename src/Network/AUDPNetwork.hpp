//
// Created by Hugo on 11/29/2019.
//

#ifndef R_TYPE_AUDPNETWORK_HPP
#define R_TYPE_AUDPNETWORK_HPP

#include <boost/asio.hpp>
#include <iostream>

namespace ecs::network {

    using boost::asio::ip::udp;

    class AUDPNetwork {
        public:
        explicit AUDPNetwork(const std::string &port) : _socket(_ioContext,
            udp::endpoint(udp::v4(), (short)std::stoi(port))), _port(port)
        {
            do_receive();
            memset(data_, 0, max_length);
        }

        AUDPNetwork(const std::string &ip, const std::string &port) : _socket(
            _ioContext, udp::endpoint(udp::v4(), 0)), _ip(ip), _port(port)
        {
            do_receive();
            memset(data_, 0, max_length);
        }

        virtual void handle_receive(boost::system::error_code ec,
            std::size_t bytes_recvd
        ) = 0;

        void run()
        {
            do_receive();
            while (!_ioContext.stopped()) {
                try {
                    _ioContext.run();
                } catch (const std::exception &e) {
                    std::cerr << "Client: network exception: " << e.what()
                        << std::endl;
                } catch (...) {
                    std::cerr << "Unknown exception in client network"
                        << std::endl;
                }
            }
        }

        void do_receive()
        {
            _socket.async_receive_from(boost::asio::buffer(data_, max_length),
                sender_endpoint_, std::bind(&AUDPNetwork::handle_receive, this,
                    std::placeholders::_1, std::placeholders::_2));
        }

        protected:
        boost::asio::io_context _ioContext;
        udp::socket _socket;
        udp::endpoint sender_endpoint_;
        std::string _ip;
        std::string _port;
        enum {
            max_length = 1024
        };
        char data_[max_length];
    };
};
#endif //R_TYPE_AUDPNETWORK_HPP
