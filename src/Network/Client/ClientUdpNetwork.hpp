//
// Created by Hugo on 11/28/2019.
//

#ifndef R_TYPE_CLIENTUDPNETWORK_HPP
#define R_TYPE_CLIENTUDPNETWORK_HPP

#include <boost/asio.hpp>

class ClientUDPNetwork {
    private:
    boost::asio::io_context _ioContext;
    boost::asio::ip::udp::socket _socket;
    boost::asio::ip::udp::resolver _resolver;
    boost::asio::ip::udp::resolver::results_type _endpoints;

    std::string _host;
    unsigned short _port;

    public:

    ClientUDPNetwork(const std::string &host, unsigned short port);

    virtual ~ClientUDPNetwork();
    void receiveHandler(const std::error_code& error, std::size_t bytesTransferred);
    void receive();
    void send(/*packet*/);
    void run();
};

#endif //R_TYPE_CLIENTUDPNETWORK_HPP
