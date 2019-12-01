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

    std::map<size_t, PlayerInfo> _playerStatus;

    bool _isGameStarted;

    std::mutex _mLock;
    std::condition_variable _cVar;

    /**
     * @brief Get the New Player Id object
     * 
     * @return size_t 
     */
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
    void addPlayer(const std::string &pseudo = "");

    /**
     * @brief stop room
     */
    void stop();
    //GETTERS & SETTERS

    /**
     * @brief Get the Id object
     * 
     * @return size_t 
     */
    size_t getId() const;

    /**
     * @brief Set the Id object
     * 
     * @param id 
     */
    void setId(size_t id);

    /**
     * @brief check if the room is open
     * 
     * @return true 
     * @return false 
     */
    bool isIsOpen() const;

    /**
     * @brief Set the Is Open object
     * 
     * @param isOpen 
     */
    void setIsOpen(bool isOpen);

    /**
     * @brief Get the Nbplayer object
     * 
     * @return size_t 
     */
    size_t getNbplayer() const;

    /**
     * @brief Set the Nbplayer object
     * 
     * @param nbplayer 
     */
    void setNbplayer(size_t nbplayer);

    /**
     * @brief Get the Nbplayer Max object
     * 
     * @return size_t 
     */
    size_t getNbplayerMax() const;

    /**
     * @brief Set the Nbplayer Max object
     * 
     * @param nbplayerMax 
     */
    void setNbplayerMax(size_t nbplayerMax);

    /**
     * @brief Get the Player Status object
     * 
     * @return const std::map<size_t, PlayerInfo>& 
     */
    const std::map<size_t, PlayerInfo> &getPlayerStatus() const;

    /**
     * @brief Check if the game is started
     * 
     * @return true 
     * @return false 
     */
    bool isIsGameStarted() const;

    /**
     * @brief Set the Is Game Started object
     * 
     * @param isGameStarted 
     */
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
};

#endif //R_TYPE_ROOM_HPP
