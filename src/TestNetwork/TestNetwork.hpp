/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** TestNetwork.hpp
*/

#ifndef TESTNETWORK_HPP_
#define TESTNETWORK_HPP_

#include <memory>
#include <boost/asio.hpp>
#include "PacketManager.hpp"

#include <ctime>
#include <chrono>
#include <iostream>

// A custom implementation of the Clock concept from the standard C++ library.
struct time_t_clock
{
    // The duration type.
    typedef std::chrono::steady_clock::duration duration;

    // The duration's underlying arithmetic representation.
    typedef duration::rep rep;

    // The ratio representing the duration's tick period.
    typedef duration::period period;

    // An absolute time point represented using the clock.
    typedef std::chrono::time_point<time_t_clock> time_point;

    // The clock is not monotonically increasing.
    static constexpr bool is_steady = false;

    // Get the current time.
    static time_point now() noexcept
    {
        return time_point() + std::chrono::seconds(std::time(0));
    }
};

struct time_t_wait_traits
{
    static time_t_clock::duration to_wait_duration(
        const time_t_clock::duration &d)
    {
        if (d > std::chrono::seconds(1))
            return d - std::chrono::seconds(1);
        else if (d > std::chrono::seconds(0))
            return std::chrono::milliseconds(10);
        else
            return std::chrono::seconds(0);
    }

    static time_t_clock::duration to_wait_duration(
        const time_t_clock::time_point &t)
    {
        return to_wait_duration(t - time_t_clock::now());
    }
};

typedef boost::asio::basic_waitable_timer<
    time_t_clock, time_t_wait_traits>
    time_t_timer;

using boost::asio::ip::udp;

class TestNetwork : public std::enable_shared_from_this<TestNetwork>
{
private:
    boost::asio::io_context _ioContext;
    udp::socket _socket;
    udp::resolver _resolver;
    udp::resolver::results_type _endpoints;
    udp::endpoint sender_endpoint_;
    ecs::network::PacketManager _ecs_packet;
    time_t_timer _timer;

    std::string _ip;
    std::string _port;
    enum
    {
        max_length = 1024
    };
    char data_[max_length];

public:
    TestNetwork(const std::string &ip, const std::string &port);
    ~TestNetwork();

    void doReceive();
    void handleReceive(boost::system::error_code ec, std::size_t bytes_recvd);
    void doSend();
    void handleSend(boost::system::error_code ec, std::size_t bytes_recvd);
    void start();

    void checkTimeOut();
    void handleTimeOut();

    void askListRoom();
    void manageListRoom();
};

#endif //TESTNETWORK_HPP_