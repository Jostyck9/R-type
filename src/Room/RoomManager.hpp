#ifndef R_TYPE_ROOMMANAGER_HPP
#define R_TYPE_ROOMMANAGER_HPP

#include <cstddef>
#include <vector>
#include "Room.hpp"

class RoomManager {

    private:

    size_t _nbRoom;
    size_t _lastId;
    std::vector<Room> _rooms;

    public:

    virtual ~RoomManager();

    RoomManager(const size_t &nbRoom);

    void closeRoom(const size_t &roomId);
    void openNewRoom();
};

#endif //R_TYPE_ROOMMANAGER_HPP
