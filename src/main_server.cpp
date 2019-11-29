/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** main_server.cpp
*/

#include <cstdlib>
#include <iostream>
#include <boost/asio.hpp>
#include <map>
#include "Session.hpp"

using boost::asio::ip::udp;

class server {
    public:
    server(boost::asio::io_context &io_context, short port) : socket_(
        io_context, udp::endpoint(udp::v4(), port))
    {
        do_receive();
        memset(data_, 0, max_length);
    }

    void handle_receive(boost::system::error_code ec, std::size_t bytes_recvd)
    {
        std::cout << ec << " " << bytes_recvd << std::endl;
        if (!ec && bytes_recvd > 0) {
            if (_sessions.find(sender_endpoint_) != _sessions.end()) {
                _sessions[sender_endpoint_]->manage_data(data_);
            } else {
                _sessions[sender_endpoint_] = std::make_shared<Session>(socket_,
                    sender_endpoint_);
                _sessions[sender_endpoint_]->manage_data(data_);
                std::cout << "sessions size : " << _sessions.size()
                    << std::endl;
            }
        }
        do_receive();
    }

    void do_receive()
    {
        socket_.async_receive_from(boost::asio::buffer(data_, max_length),
            sender_endpoint_,
            std::bind(&server::handle_receive, this, std::placeholders::_1,
                std::placeholders::_2));
    }

    /*void do_send(std::size_t length)
    {
        socket_.async_send_to(boost::asio::buffer(data_, length),
            sender_endpoint_, [this](
            ) {
                do_receive();
            });
    }*/

    private:
    udp::socket socket_;
    udp::endpoint sender_endpoint_;
    enum {
        max_length = 1024
    };
    char data_[max_length];

    std::map<udp::endpoint, std::shared_ptr<ISession>> _sessions;
};

int main(int argc, char *argv[])
{
    try {
        if (argc != 2) {
            std::cerr << "Usage: async_udp_echo_server <port>\n";
            return 1;
        }

        boost::asio::io_context io_context;

        server s(io_context, (short)std::atoi(argv[1]));

        io_context.run();
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}
