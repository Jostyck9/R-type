#ifndef __THREADPOOL_HPP__
# define __THREADPOOL_HPP__

#include <thread>

#define MAX_THREAD std::thread::hardware_concurency()

class ThreadPool {
private:
public:
    ThreadPool() = default;
    ThreadPool(const ThreadPool&) = delete;

    ThreadPool &operator=(const ThreadPool&) = delete;




};

#endif // !__THREADPOOL_HPP__
