#include <iostream>

#include "Room/RoomManager.hpp"

int main(int, char**) {

    RoomManager rooms(4);

    for (auto &r : rooms.getRooms()) {
        rooms.addTask([&]() { r->run(); });
    }

    //std::cout << rooms.getRooms().at(1)->getId() << std::endl;
    rooms.getRooms().at(1)->addPlayer();
    //std::cout << rooms.getRooms().at(1)->getId() << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(10));
    rooms.stop();
    return (0);
}
