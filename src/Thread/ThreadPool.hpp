#ifndef __THREADPOOL_HPP__
# define __THREADPOOL_HPP__

#include <thread>
#include <queue>
#include <future>
#include <vector>
#include <memory>
#include <utility>
#include <type_traits>

#define MAX_THREAD std::thread::hardware_concurency()

class ThreadPool {
private:

    class Worker {
    private:
        ThreadPool *_pool;
        size_t _id;
        bool _isStopped;

        std::queue<std::packaged_task<void()> > _tasksQueue;

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

        void operator()();

    };

    std::vector<std::thread> _poolThread;
    std::vector<Worker> _poolWorker;
    size_t _poolSize;
    
    
public:

    ThreadPool() = default;
    ThreadPool(size_t size);
    ThreadPool(const ThreadPool&) = default;
    ~ThreadPool();
    ThreadPool &operator=(const ThreadPool&) = default;

    void stop();
    void destroy();

    size_t getFreeWorker();

    
    template <typename T_>
    using decay_t = typename std::decay<T_>::type;
    template< class T >
    using result_of_t = typename std::result_of<T>::type;

    template<typename Function, typename ... Args>
    auto run(Function&& f, Args&& ... args) -> std::future<typename std::result_of<Function(Args...)>>
    {

        auto task =
            std::packaged_task<typename std::result_of<Function(Args...)>::type>(std::bind(std::forward<Function>(f), std::forward<Args>(args)...));
        auto result = task.get_future();

        size_t id = getFreeWorker();

        auto worker = _poolWorker.at(id);
       
    };

};

#endif // !__THREADPOOL_HPP__
