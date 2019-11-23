/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Session.hpp
*/

#ifndef SESSION_HPP__
#define SESSION_HPP__

#include "ISession.hpp"

class Session : public std::enable_shared_from_this<Session>, public ISession
{
private:
    udp::endpoint &_sender_endpoint;
    udp::socket &_socket;

    enum { max_length = 1024 };
    size_t recv;

public:
    Session(udp::socket &_socket, udp::endpoint &senderEndpoint);
    ~Session();

    void do_write(char data[max_length]);
    void handle_write(boost::system::error_code ec, std::size_t length);

    void manage_data(char rawData[max_length]) override;
};
#endif //SESSION_HPP__