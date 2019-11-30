/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** PacketManager.cpp
*/

#include <cstring>
#include "PacketManager.hpp"

namespace ecs::network
{

PacketManager::PacketManager()
{
    clear();
}

PacketManager::PacketManager(const PacketManager &other)
{
    clear();
    std::memcpy(packet.rawData, other.packet.rawData, MAX_LENGTH);
}

PacketManager::~PacketManager()
{
}

void PacketManager::clear()
{
    std::memset(packet.rawData, 0, MAX_LENGTH);
    packet.data.magicNumber = 42;
    setRes(true);
}

void PacketManager::setCmd(const CMD cmd)
{
    packet.data.typeCmd = cmd;
}

void PacketManager::setRes(bool res)
{
    packet.data.res = res;
}

void PacketManager::setJoinRoom(char roomId)
{
    setCmd(JOINROOM);
    setRes(true);
    packet.data._join.id = roomId;
}

int PacketManager::addEntity(size_t gameId)
{
    setCmd(UPDATE);
    setRes(true);
    if (packet.data._entities.size == MAX_ENTITIES)
        return -1;
    packet.data._entities.list[static_cast<int>(packet.data._entities.size)].id = gameId;
    return packet.data._entities.size++;
}

int PacketManager::addEntity(Entity entity)
{
    setCmd(UPDATE);
    setRes(true);
    if (packet.data._entities.size == MAX_ENTITIES)
        return -1;
    packet.data._entities.list[static_cast<int>(packet.data._entities.size)] = entity;
    return packet.data._entities.size++;
}

bool PacketManager::addPosition(int entityIndex, float x, float y)
{
    setCmd(UPDATE);
    setRes(true);
    if (entityIndex < 0 || entityIndex >= packet.data._entities.size || packet.data._entities.list[entityIndex].nbrComponents >= MAX_COMPONENTS)
        return false;
    packet.data._entities.list[entityIndex].components[static_cast<int>(packet.data._entities.list[entityIndex].nbrComponents)].type = POSITION;
    packet.data._entities.list[entityIndex].components[static_cast<int>(packet.data._entities.list[entityIndex].nbrComponents)]._position.x = x;
    packet.data._entities.list[entityIndex].components[static_cast<int>(packet.data._entities.list[entityIndex].nbrComponents)]._position.x = y;
    return true;
}

bool PacketManager::addRotation(int entityIndex, float angleRad)
{
    setCmd(UPDATE);
    setRes(true);
    if (entityIndex < 0 || entityIndex >= packet.data._entities.size || packet.data._entities.list[entityIndex].nbrComponents >= MAX_COMPONENTS)
        return false;
    packet.data._entities.list[entityIndex].components[static_cast<int>(packet.data._entities.list[entityIndex].nbrComponents)].type = ROTATION;
    packet.data._entities.list[entityIndex].components[static_cast<int>(packet.data._entities.list[entityIndex].nbrComponents)]._rotation.radAngle = angleRad;
    return true;
}

int PacketManager::addRoom(const Room &room)
{
    setCmd(GETROOMS);
    setRes(true);
    if (packet.data._getRoom.size == MAX_ENTITIES)
        return -1;
    packet.data._getRoom.listRoom[static_cast<int>(packet.data._getRoom.size)] = room;
    return packet.data._getRoom.size++;
}

bool PacketManager::isSuccessful() const
{
    return packet.data.res;
}

PacketManager::CMD PacketManager::getCmd() const
{
    return packet.data.typeCmd;
}

const PacketManager::IsReady PacketManager::getIsReady() const
{
    return packet.data._isReady;
}

const PacketManager::JoinRoom PacketManager::getJoinRoom() const
{
    return packet.data._join;
}

const PacketManager::GetRooms PacketManager::getListRooms() const
{
    return packet.data._getRoom;
}

const PacketManager::Entities PacketManager::getListEntities() const
{
    return packet.data._entities;
}

const char *PacketManager::getRawData() const
{
    return packet.rawData;
}

char PacketManager::getMagicNumber() const
{
    return packet.data.magicNumber;
}

void PacketManager::setMsg(const std::string &msg)
{
    size_t size = MAX_MSG_LENGTH;

    if (msg.size() < MAX_MSG_LENGTH)
        size = msg.size();
    std::strncpy(packet.data._msg, msg.c_str(), size);
}

const std::string PacketManager::getMsg()
{
    std::string msg;

    msg = packet.data._msg;
    return msg;
}

const PacketManager::KeysPressed PacketManager::getKeys() const
{
    return packet.data._keys;
}

int PacketManager::addKey(const ecs::input::Key keyPressed)
{
    setCmd(UPDATE);
    if (packet.data._keys.size == MAX_KEYS)
        return -1;
    packet.data._keys.list[static_cast<int>(packet.data._keys.size)] = keyPressed;
    return packet.data._keys.size++;
}

} // namespace ecs::network