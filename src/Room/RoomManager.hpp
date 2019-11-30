#ifndef R_TYPE_ROOMMANAGER_HPP
#define R_TYPE_ROOMMANAGER_HPP

#include <cstddef>
#include <vector>
#include <memory>
#include "Room.hpp"
#include <boost/asio.hpp>

class RoomManager {

    private:

    size_t _nbRoom;

    std::vector<std::shared_ptr<Room>> _rooms;

    boost::asio::thread_pool _pool;

    public:

    virtual ~RoomManager();

    /**
     * @brief Construct a new RoomManager with nbRoom
     *  optionally you can choose the number of player per room
     * @param nbRoom
     * @param nbPlayer
     */
    explicit RoomManager(size_t nbRoom, size_t nbPlayer = 4);

    /**
     * @brief add a task to the threadpool
     * @param f
     */
    void addTask(const std::function<void()> &f);

    /**
     * @brief return access to the rooms
     * @return
     */
    std::vector<std::shared_ptr<Room>> &getRooms();

    size_t getNbRoom() const;

    /**
     * @brief stop the threadpool and the room
     */
    void stop();

};

#endif //R_TYPE_ROOMMANAGER_HPP
