#ifndef __THREADPOOL_HPP__
# define __THREADPOOL_HPP__

#include "Room.hpp"
#include <vector>

#define MAX_THREAD std::thread::hardware_concurency()

class ThreadPool {
private:
    std::vector<Room> _room;

    ThreadPool() = default;

public:

    /**
     * @brief getInstance return single instance of ThreadPool to manage rooms and worker.
     *
     */
    static ThreadPool& getInstance();

    ThreadPool(const ThreadPool&) = delete;
    ThreadPool &operator=(const ThreadPool&) = delete;


};

#endif // !__THREADPOOL_HPP__
