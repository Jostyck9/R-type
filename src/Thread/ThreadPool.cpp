#include "ThreadPool.hpp"
#include <iostream>

ThreadPool::ThreadPool(size_t size) : _poolSize(size), _poolThread(), _poolWorker()
{

    std::cout << size << " " << _poolSize << std::endl;

    for (size_t i = 0; i < _poolSize; i++)
    {
        auto nworker = ThreadPool::Worker(this, i);
        _poolWorker.emplace_back(nworker);
        _poolThread.emplace_back(std::thread(nworker));
    }

    for (auto& work : _poolWorker)
        work.start();
}

ThreadPool::~ThreadPool()
{
    stop();
    destroy();
}

void ThreadPool::stop()
{
    for (auto& it : _poolWorker) {
        it.stop();
    }
}

void ThreadPool::destroy()
{
    for (auto& it : _poolThread) {
        it.join();
    }
}

size_t ThreadPool::getFreeWorker()
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


ThreadPool::Worker::Worker(ThreadPool *pool, size_t id) : _pool(pool), _id(id), _isStopped(true)
{
}

ThreadPool::Worker::Worker(const Worker& cpWorker) : _pool(cpWorker._pool), _id(cpWorker._id), _isStopped(true)
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
    std::lock_guard<std::mutex> lock(_taskLock);
    _isStopped = false;
    _condVar.notify_one();
}

void ThreadPool::Worker::stop()
{
    std::lock_guard<std::mutex> lock(_taskLock);
    _isStopped = true;
    _condVar.notify_one();
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
    std::unique_lock<std::mutex> glock(_taskLock);
    _condVar.wait(glock, [&]() {return _isStopped == false; });
}

bool ThreadPool::Worker::isQueueEmpty()
{
    return _tasksQueue.empty();
}

size_t ThreadPool::Worker::getTaskQueueSize()
{
    return _tasksQueue.size();
}

void ThreadPool::Worker::operator()()
{
    waitForStart();

    std::unique_lock<std::mutex> lock(_taskLock);
    _condVar.wait(lock, [&]() {
        return _isStopped || !isQueueEmpty();
        });
    auto task = std::move(_tasksQueue.front());
    _tasksQueue.pop();
    task();
}
