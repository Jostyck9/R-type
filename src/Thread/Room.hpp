#ifndef __ROOM_HPP__
# define __ROOM_HPP__

#include "Worker.hpp"
#include "Task.hpp"
#include <vector>
#include <queue>

class Room {
private:
    uint16_t _state;
    std::vector<Worker> _workers;
    size_t _id;
    std::queue<Task> _tasks;
public:
    Room();
    ~Room();


};

#endif // !__ROOM_HPP__