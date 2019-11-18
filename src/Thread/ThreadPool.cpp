#include "ThreadPool.hpp"

ThreadPool& ThreadPool::getInstance()
{
    return ThreadPool();
}
