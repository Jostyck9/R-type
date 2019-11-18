#ifndef __WORKER_HPP__
# define __WORKER_HPP__

class Worker {
private:
public:
    Worker() = default;
    Worker(const Worker&) = delete;

    Worker& operator=(const Worker&) = delete;
};

#endif // !__WORKER_HPP__
