#ifndef __WORKER_HPP__
# define __WORKER_HPP__

#include <thread>

class Worker {
private:
    std::thread _worker;
public:
    Worker() = default;
    Worker(const Worker&) = delete;

    Worker& operator=(const Worker&) = delete;
};

#endif // !__WORKER_HPP__
