/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** ServerSession.cpp
*/

#include <iostream>
#include <memory>
#include <PacketManager.hpp>
#include "ServerSession.hpp"

ecs::network::ServerSession::~ServerSession() = default;

void ecs::network::ServerSession::do_write(const char rawData[max_length])
{
    _socket.async_send_to(boost::asio::buffer(rawData, max_length),
        _sender_endpoint, std::bind(&ecs::network::ServerSession::handle_write,
            shared_from_this(), std::placeholders::_1, std::placeholders::_2));
}

void ecs::network::ServerSession::handle_write(boost::system::error_code ec,
    std::size_t length
)
{
    if (ec) {
        std::cerr << "error : " << ec << "\t" << length << " bytes sent"
            << std::endl;
    }
    if (isPacketValid()) {
        if (_functionsProtocol.find(_packet.getCmd()) ==
            _functionsProtocol.end()) {
            setMsgPacket("Error command not found");
            do_write(_packet.packet.rawData);
        } else {
            (this->*(_functionsProtocol[_packet.getCmd()]))();
        }
    }
}

void ecs::network::ServerSession::manage_data(const char rawData[max_length])
{
    std::cout << "sent from :" << _sender_endpoint.address().to_string()
        << std::endl;
    std::cout << "Packet received" << std::endl;

    std::memcpy(_packet.packet.rawData, rawData, max_length);
    do_write(rawData);
}

const ecs::network::ServerSession::SessionInfo &ecs::network::ServerSession::getInfo() const
{
    return _info;
}

ecs::network::ServerSession::ServerSession(udp::socket &socket,
    udp::endpoint &senderEndpoint, RoomManager &roomManager, const size_t &id
) : _sender_endpoint(senderEndpoint), _socket(socket),
    _roomManager(roomManager), _id(id)
{
    _info.isConnected = false;
    _info.isInRoom = false;
    _info.roomId = 0;

    _functionsProtocol[ecs::network::PacketManager::JOINROOM] = &ecs::network::ServerSession::manageJoinRoom;
    _functionsProtocol[ecs::network::PacketManager::LEAVEROOM] = &ecs::network::ServerSession::manageLeaveRoom;
    _functionsProtocol[ecs::network::PacketManager::LAUNCHGAME] = &ecs::network::ServerSession::manageLaunchGame;
    _functionsProtocol[ecs::network::PacketManager::GETROOMS] = &ecs::network::ServerSession::manageGetRooms;
    _functionsProtocol[ecs::network::PacketManager::ISREADY] = &ecs::network::ServerSession::manageIsReady;
    _functionsProtocol[ecs::network::PacketManager::UPDATE] = &ecs::network::ServerSession::manageUpdate;
    _functionsProtocol[ecs::network::PacketManager::HANDSHAKE] = &ecs::network::ServerSession::manageHandShake;
}

bool ecs::network::ServerSession::manageLeaveRoom()
{
    if (_info.isConnected) {
        if (_info.isInRoom) {
            _roomManager.getRoomById(_info.roomId)->deletePlayer(_id);
            _info.roomId = 0;
            _info.isInRoom = false;
            return true;
        }
        setMsgPacket("Error not inside a room");
        do_write(_packet.packet.rawData);
        return false;
    }
    setMsgPacket("Error not connected");
    do_write(_packet.packet.rawData);
    return false;
}

bool ecs::network::ServerSession::manageJoinRoom()
{
    if (_info.isConnected) {
        if (!_info.isInRoom) {
            auto r = _roomManager.getRoomById(_packet.getJoinRoom().id);
            r->addPlayer(_id);
            _info.roomId = _packet.getJoinRoom().id;
            _info.isInRoom = true;
            return true;
        }
        setMsgPacket("Error already in a room");
        do_write(_packet.packet.rawData);
        return false;
    }
    setMsgPacket("Error not connected");
    do_write(_packet.packet.rawData);
    return false;
}

bool ecs::network::ServerSession::manageGetRooms()
{
    if (_info.isConnected) {
        ecs::network::PacketManager::Room packetRoom;
        for (auto &r : _roomManager.getRooms()) {
            packetRoom.id = r->getId();
            packetRoom.isOpen = r->isIsOpen();
            packetRoom.isStarted = r->isIsGameStarted();
            packetRoom.nbPlayerMax = r->getNbplayerMax();
            packetRoom.nbPlayers = r->getNbplayer();
            for (auto &p : r->getPlayerStatus()) {
                packetRoom.players->isReady = p.second._isReady;
                std::memcpy(packetRoom.players->pseudo,
                    std::to_string(p.first).c_str(),
                    std::to_string(p.first).size());
            }
            if (_packet.addRoom(packetRoom) == -1) {
                break;
            }
        }
        do_write(_packet.packet.rawData);
        return true;
    }
    setMsgPacket("Error not connected");
    do_write(_packet.packet.rawData);
    return false;
}

bool ecs::network::ServerSession::manageHandShake()
{
    _info.isConnected = true;
    do_write(_packet.packet.rawData);
    return true;
}

bool ecs::network::ServerSession::manageIsReady()
{
    if (_info.isConnected) {
        if (_info.isInRoom) {
            _roomManager.getRoomById(_info.roomId)->setPlayerStatus(_id,
                _packet.packet.data._isReady.isReady);
            return true;
        }
        setMsgPacket("Error not inside a room");
        do_write(_packet.packet.rawData);
        return false;
    }
    setMsgPacket("Error not connected");
    do_write(_packet.packet.rawData);
    return false;
}

bool ecs::network::ServerSession::manageLaunchGame()
{
    if (_info.isConnected) {
        if (_info.isInRoom) {
            if (_roomManager.getRoomById(_info.roomId)->getPlayerReady() ==
                _roomManager.getRoomById(_info.roomId)->getNbplayer()) {
                _roomManager.getRoomById(_info.roomId)->setIsGameStarted(true);
                return true;
            } else {
                setMsgPacket("Error all player are not ready");
                do_write(_packet.packet.rawData);
                return false;
            }
        }
        setMsgPacket("Error not inside a room");
        do_write(_packet.packet.rawData);
        return false;
    }
    setMsgPacket("Error not connected");
    do_write(_packet.packet.rawData);
    return false;
}

bool ecs::network::ServerSession::manageUpdate()
{
    if (_info.isConnected) {
        if (_info.isInRoom) {
            //TODO if game started
            return true;
        }
        setMsgPacket("Error not inside a room");
        do_write(_packet.packet.rawData);
        return false;
    }
    setMsgPacket("Error not connected");
    do_write(_packet.packet.rawData);
    return false;
}

bool ecs::network::ServerSession::isPacketValid()
{
    return _packet.getMagicNumber() == 42;
}

bool ecs::network::ServerSession::setMsgPacket(const std::string &msg)
{
    _packet.setMsg(msg);
    return false;
}
