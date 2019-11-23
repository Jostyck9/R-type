/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** ISession.hpp
*/

#ifndef ISESSION__HPP__
#define ISESSION__HPP__

#include <memory>
#include <boost/asio.hpp>

using boost::asio::ip::udp;

class ISession : public std::enable_shared_from_this<ISession>
{
public:
    virtual bool start() = 0;
    virtual bool stop() = 0;
    virtual boost::asio::ip::udp::socket &getSocket() = 0;
};

#endif //ISESSION__HPP__