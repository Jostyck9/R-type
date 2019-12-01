#include <iostream>
#include "Room.hpp"

Room::Room(const size_t &id) : _id(id), _isOpen(true), _nbPlayer(0), _nbPlayerMax(4), _isGameStarted(false)
{
}

Room::~Room()
{
}

Room::Room(size_t id, size_t nbPlayerMax) : _id(id), _isOpen(true), _nbPlayer(0), _nbPlayerMax(nbPlayerMax), _isGameStarted(false)
{
}

size_t Room::getPlayerReady()
{
    size_t nbrp = 0;

    if (getNbplayer() == 0)
        return 0;
    for (auto &p : _playerStatus)
    {
        if (p.second._isReady == true)
            nbrp++;
    }
    return nbrp;
}

void Room::addPlayer(const size_t &id, const std::string &pseudo)
{
    std::lock_guard<std::mutex> lock(_mLock);
    PlayerInfo pInfo;

    pInfo._isReady = false;
    pInfo._pseudo = pseudo;
    _playerStatus.emplace(std::make_pair(id, pInfo));
    _nbPlayer++;
    _cVar.notify_one();
}

void Room::run()
{
    //TODO implement game in here

    //TODO Init ecs here and do update in here

    while (_isOpen)
    {
        //TODO do the flop and the game
        std::unique_lock<std::mutex> Lock(_mLock);
        displayRoomStatus();
        _cVar.wait(Lock);
    }
}

void Room::displayRoomStatus()
{
    std::cout << "Room id : " << getId() << std::endl;
    std::cout << "Status : " << (_isOpen ? "Open" : "Close") << std::endl;
    std::cout << "\tPlayer : " << getNbplayer() << "/" << getNbplayerMax()
              << std::endl;
    std::cout << "\tPlayer ready: " << getPlayerReady() << "/" << getNbplayer()
              << std::endl;
    std::cout << "\t" << (_isGameStarted ? "Started" : "Waiting for player")
              << std::endl;
}

size_t Room::getNbplayer() const
{
    return _nbPlayer;
}

void Room::setNbplayer(size_t nbplayer)
{
    _nbPlayer = nbplayer;
}

size_t Room::getNbplayerMax() const
{
    return _nbPlayerMax;
}

void Room::setNbplayerMax(size_t nbplayerMax)
{
    _nbPlayerMax = nbplayerMax;
}

const std::map<size_t, PlayerInfo> &Room::getPlayerStatus() const
{
    return _playerStatus;
}

bool Room::isIsGameStarted() const
{
    return _isGameStarted;
}

void Room::setIsGameStarted(bool isGameStarted)
{
    _isGameStarted = isGameStarted;
}

size_t Room::getNewPlayerId()
{
    return _lastIdAvailable++;
}

size_t Room::getId() const
{
    return _id;
}

void Room::setId(size_t id)
{
    _id = id;
}

bool Room::isIsOpen() const
{
    return _isOpen;
}

void Room::setIsOpen(bool isOpen)
{
    _isOpen = isOpen;
}

void Room::stop()
{
    std::lock_guard<std::mutex> lock(_mLock);

    setIsOpen(false);
    setIsGameStarted(false);

    _cVar.notify_one();
}

bool Room::isGameReady()
{
    return getPlayerReady() == getNbplayer();
}

void Room::deletePlayer(const size_t &id)
{
    std::lock_guard<std::mutex> lock(_mLock);
    _playerStatus.erase(id);
    _nbPlayer--;
    _cVar.notify_one();
}

PlayerInfo &Room::getPlayerById(const size_t &id)
{
    return _playerStatus[id];
}

void Room::setPlayerStatus(const size_t &id, bool ready)
{
    getPlayerById(id)._isReady = ready;
}
