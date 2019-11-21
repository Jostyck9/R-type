#include <iostream>
#include "Thread/ThreadPool.hpp"

int test(int i, int j) {
    return i + j;
}

void test1(std::string& str) {
    std::cout << str << std::endl;
}

int main(int, char**) {

    ThreadPool pool(5);

    pool.run(&test, 2, 4);
    return (0);
}
