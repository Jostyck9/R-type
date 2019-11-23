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

        std::function<void()>& fetchTask();

        void operator()();

    };

    std::vector<std::thread> _poolThread;
    std::vector<Worker> _poolWorker;
    size_t _poolSize;
    bool _isStopped;

    std::mutex _poolLock;
    std::condition_variable _poolCondVar;
    
public:

    ThreadPool() = default;
    explicit ThreadPool(size_t size);
    ~ThreadPool();

    void start();
    void stop();
    void destroy();

    size_t getFirstFreeWorker();

    size_t getBusyWorker();
    size_t getFreeWorker();

    void run(std::function<void()> const& f);

};

#endif // !__THREADPOOL_HPP__
