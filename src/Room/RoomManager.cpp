#include "RoomManager.hpp"

RoomManager::~RoomManager()
{
    _pool.join();
}

RoomManager::RoomManager(size_t nbRoom, size_t nbPlayer) : _nbRoom(nbRoom), _pool(_nbRoom)
{
    for (size_t i = 0; i < _nbRoom; ++i) {
        _rooms.emplace_back(std::make_shared<Room>(i+1, nbPlayer));
    }

}

void RoomManager::addTask(const std::function<void()> &f)
{
    boost::asio::post(_pool, f);
}

std::vector<std::shared_ptr<Room>> &RoomManager::getRooms()
{
    return _rooms;
}

size_t RoomManager::getNbRoom() const
{
    return _nbRoom;
}

void RoomManager::stop()
{
    for (auto &r : getRooms()) {
        r->stop();
    }

    _pool.stop();
}

