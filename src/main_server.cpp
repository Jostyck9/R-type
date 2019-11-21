#include <iostream>
#include "Thread/ThreadPool.hpp"

int test(int i, int j) {
    std::cout << "i = " << i << std::endl << "j = " << j << std::endl << "i + j = " << i + j << std::endl;
    return i + j;
}

void test1(std::string& str) {
    std::cout << str << std::endl;
}

int main(int, char**) {

    ThreadPool *pool = new ThreadPool(5);
    std::cout << "Thread n° " << std::this_thread::get_id() << std::endl;
    std::function<int(int, int)> f = test;
    pool->run([&]() {std::cout << "Thread n° " << std::this_thread::get_id() << std::endl; });
    pool->run([&]() {std::cout << "Thread n° " << std::this_thread::get_id() << std::endl; });
    pool->run([&]() {std::cout << "Thread n° " << std::this_thread::get_id() << std::endl; });
    pool->run([&]() {std::cout << "Thread n° " << std::this_thread::get_id() << std::endl; });
    pool->run([&]() {std::cout << "Thread n° " << std::this_thread::get_id() << std::endl; });
    pool->run([&]() {std::cout << "Thread n° " << std::this_thread::get_id() << std::endl; });
    pool->run([&]() {std::cout << "Thread n° " << std::this_thread::get_id() << std::endl; });
    pool->run([&]() {std::cout << "Thread n° " << std::this_thread::get_id() << std::endl; });

    return (0);
}
