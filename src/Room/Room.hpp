#ifndef R_TYPE_ROOM_HPP
#define R_TYPE_ROOM_HPP

#include <map>
#include <string>
#include <mutex>
#include <condition_variable>

struct PlayerInfo {
    std::string _pseudo;
    bool _isReady;
};

class Room {
    private:
    // TODO Add ecs
    size_t _id;
    bool _isOpen;
    size_t _nbPlayer;
    size_t _nbPlayerMax;
    size_t _lastIdAvailable = 0;

    //TODO add queue in / out
    //TODO Change or add session in room one way or another


    std::map<size_t, PlayerInfo> _playerStatus;

    bool _isGameStarted;

    std::mutex _mLock;
    std::condition_variable _cVar;

    size_t getNewPlayerId();

    public:
    /**
     * @brief Create new Room
     * @param id
     */
    explicit Room(const size_t &id);

    /**
     * @brief Create new Room of capacity nbPlayrMax
     * @param id
     * @param nbPlayerMax
     */
    Room(size_t id, size_t nbPlayerMax);

    virtual ~Room();

    /**
     * @brief start the room and wait for player to join and get ready
     */
    void run();

    /**
     * @brief display room status on standart output
     */
    void displayRoomStatus();

    /**
     * @brief add a player to the room up to nbPlayerMax
     * @param pseudo
     */
    void addPlayer(const size_t &id, const std::string &pseudo = "");

    void deletePlayer(const size_t &id);

    /**
     * @brief stop room
     */
    void stop();
    //GETTERS & SETTERS

    size_t getId() const;

    void setId(size_t id);

    bool isIsOpen() const;

    void setIsOpen(bool isOpen);

    size_t getNbplayer() const;

    void setNbplayer(size_t nbplayer);

    size_t getNbplayerMax() const;

    void setNbplayerMax(size_t nbplayerMax);

    const std::map<size_t, PlayerInfo> &getPlayerStatus() const;

    bool isIsGameStarted() const;

    void setIsGameStarted(bool isGameStarted);

    /**
     * @brief return number of player ready
     * @return
     */
    size_t getPlayerReady();

    /**
     * @brief return true if game is ready to start (if all player in room are ready)
     * @return
     */
    bool isGameReady();

    void setPlayerStatus(const size_t & id, bool ready);

    PlayerInfo &getPlayerById(const size_t &id);
};

#endif //R_TYPE_ROOM_HPP
