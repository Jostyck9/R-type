#ifndef __THREADPOOL_HPP__
# define __THREADPOOL_HPP__

#include <thread>
#include <queue>
#include <future>
#include <vector>
#include <memory>
#include <utility>
#include <type_traits>
#include <functional>

#define MAX_THREAD std::thread::hardware_concurency()

class ThreadPool {
private:

    class Worker {
    private:
        ThreadPool *_pool;
        size_t _id;
        bool _isStopped;

        std::queue<std::function<void()> > _tasksQueue;

        std::mutex _taskLock;
        std::condition_variable _condVar;
    public:
        explicit Worker(ThreadPool *pool, size_t _id);
        Worker(const Worker&);
        ~Worker();

        Worker();

        void start();
        void stop();
        bool isStopped();
        const size_t getId();
        void waitForStart();

        bool isQueueEmpty();
        size_t getTaskQueueSize();

        void addTask(std::function<void()> const& f);

        void operator()();

    };

    std::vector<std::thread> _poolThread;
    std::vector<Worker> _poolWorker;
    size_t _poolSize;
    bool _isStopped;
    
public:

    ThreadPool() = default;
    ThreadPool(size_t size);
    ThreadPool(const ThreadPool&) = default;
    ~ThreadPool();
    ThreadPool &operator=(const ThreadPool&) = default;

    void stop();
    void destroy();

    size_t getFreeWorker();

    void run(std::function<void()> const &f) {
        size_t id = getFreeWorker();
        auto worker = _poolWorker.at(id);
        worker.addTask(f);
    };

};

#endif // !__THREADPOOL_HPP__
