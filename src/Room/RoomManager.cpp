#include "RoomManager.hpp"

RoomManager::~RoomManager()
{
}

RoomManager::RoomManager(const size_t &nbRoom) : _nbRoom(nbRoom), _lastId(_nbRoom-1)
{
    for (int i = 0; i < _nbRoom; ++i) {
        _rooms.emplace_back(Room(i));
    }
}

void RoomManager::closeRoom(const size_t &roomId)
{
    for (auto &r : _rooms) {
        if (r.getId() == roomId)
            r.setIsOpen(false);
    }
}

void RoomManager::openNewRoom()
{
    _rooms.emplace_back(Room(++_lastId));
}
