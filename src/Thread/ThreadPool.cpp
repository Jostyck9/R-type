#include "ThreadPool.hpp"
#include <thread>
#include <iostream>

//==================================/       THREADPOOL      \====================================\\

ThreadPool::ThreadPool(size_t size) : _poolSize(size), _poolThread(),
    _poolWorker(), _isStopped(true)
{

    for (size_t i = 0; i < _poolSize; i++) {
        _poolWorker.emplace_back(ThreadPool::Worker(this, i));
        _poolThread.emplace_back(std::thread(_poolWorker.at(i)));
    }

    std::unique_lock<std::mutex> lock(_poolLock);
    _poolCondVar.wait(lock);
    lock.unlock();
    lock.release();
    std::cout << "Pool got notified\n";
    start();
}

ThreadPool::~ThreadPool()
{
    stop();
    destroy();
}

void ThreadPool::start()
{
    _isStopped = false;
    std::lock_guard<std::mutex> glock(_poolLock);
    for (auto &work : _poolWorker)
        work.start();
}

void ThreadPool::stop()
{
    _isStopped = true;
    std::lock_guard<std::mutex> glock(_poolLock);
    for (auto &it : _poolWorker) {
        it.stop();
    }
}

void ThreadPool::destroy()
{
    std::lock_guard<std::mutex> glock(_poolLock);
    for (auto &it : _poolThread) {
        it.join();
    }
}

size_t ThreadPool::getFirstFreeWorker()
{
    std::pair<int, int> fWorker;

    fWorker = std::make_pair(-1, -1);
    for (auto &it : _poolWorker) {
        if (fWorker.first == -1) {
            fWorker.first = it.getId();
            fWorker.second = it.getTaskQueueSize();
        }
        if (it.isQueueEmpty())
            return (it.getId());
        if (fWorker.second > it.getTaskQueueSize()) {
            fWorker.first = it.getId();
            fWorker.second = it.getTaskQueueSize();
        }
    }
    return fWorker.first;
}

size_t ThreadPool::getBusyWorker()
{
    size_t bworker = 0;
    for (auto &w : _poolWorker)
        if (!w.isStopped())
            bworker++;
    return bworker;
}

size_t ThreadPool::getFreeWorker()
{
    size_t bworker = 0;
    for (auto &w : _poolWorker)
        if (w.isStopped())
            bworker++;
    return bworker;
}

void ThreadPool::run(std::function<void()> const &f)
{
    std::cout << "Run\n";
    std::unique_lock<std::mutex> lock(_poolLock);
    size_t id = getFirstFreeWorker();
    std::cout << "Worker id " << id << std::endl;
    _poolWorker.at(id).addTask(f);
}

//==================================/       WORKER      \====================================\\

ThreadPool::Worker::Worker(ThreadPool *pool, size_t id) : _pool(pool), _id(id),
    _isStopped(_pool->_isStopped)
{
}

ThreadPool::Worker::Worker(const Worker &cpWorker) : _pool(cpWorker._pool),
    _id(cpWorker._id), _isStopped(true)
{
}

ThreadPool::Worker::~Worker()
{
    stop();
}

ThreadPool::Worker::Worker() : _pool(nullptr), _id(0), _isStopped(true)
{
}

void ThreadPool::Worker::start()
{
    {
        std::lock_guard<std::mutex> lock(_taskLock);
        _isStopped = false;
    }

    _condVar.notify_one();
    std::cout << "Notify from worker start\n";
}

void ThreadPool::Worker::stop()
{
    {
        std::lock_guard<std::mutex> lock(_taskLock);
        _isStopped = true;
    }
    _condVar.notify_one();
    std::cout << "Notify from Worker stop\n";
}

bool ThreadPool::Worker::isStopped()
{
    return _isStopped;
}

const size_t ThreadPool::Worker::getId()
{
    return _id;
}

void ThreadPool::Worker::waitForStart()
{
}

bool ThreadPool::Worker::isQueueEmpty()
{
    return _tasksQueue.empty();
}

size_t ThreadPool::Worker::getTaskQueueSize()
{
    return _tasksQueue.size();
}

void ThreadPool::Worker::addTask(std::function<void()> const &f)
{
    {
        std::lock_guard<std::mutex> glock(_taskLock);
        _tasksQueue.push(f);
        _condVar.notify_one();
    }
    std::cout << "Notify from add task\n";
}

std::function<void()> &ThreadPool::Worker::fetchTask()
{
    for (;;) {
        std::unique_lock<std::mutex> lock(_taskLock);
        _condVar.wait(
            lock);//, [&]() {            return !_pool->_isStopped || !_isStopped || !isQueueEmpty();            });
        auto task = _tasksQueue.front();
        _tasksQueue.pop();
        return task;
    }
}

void ThreadPool::Worker::operator()()
{
    std::cout << "Wait for start from worker id " << _id << std::endl;
    std::unique_lock<std::mutex> glock(_taskLock);

    _pool->_poolCondVar.notify_one();
    std::cout << _isStopped << std::endl;
    _condVar.wait(glock);//, [&]() { return _isStopped == false; });
    //waitForStart();
    std::cout << "Started" << std::endl;

    auto task = fetchTask();
    task();
}
