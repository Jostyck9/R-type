/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Session.hpp
*/

#ifndef SESSION_HPP__
#define SESSION_HPP__

#include "ISession.hpp"

class Session : public ISession
{
private:
    boost::asio::io_context &_io_context;
    boost::asio::ip::udp::socket _socket;
    udp::endpoint &sender_endpoint_;
    enum { max_length = 1024 };
    char rawData[max_length];

public:
    Session(boost::asio::io_context &io_context, boost::asio::ip::udp::endpoint &senderEndpoint);
    ~Session();

    void do_read();
    void handle_read(boost::system::error_code ec, std::size_t length);
    void do_write();
    void handle_write(boost::system::error_code ec, std::size_t length);

    bool start() override;
    bool stop() override;
    boost::asio::ip::udp::socket &getSocket() override;
};
#endif //SESSION_HPP__