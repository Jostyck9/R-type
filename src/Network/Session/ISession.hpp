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

class ISession
{
public:
    enum { max_length = 1024 };
    virtual void manage_data(char rawData[max_length]) = 0;
};

#endif //ISESSION__HPP__