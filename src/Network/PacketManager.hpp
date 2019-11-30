/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** PacketManager.hpp
*/

#ifndef PACKETMANAGER_HPP
#define PACKETMANAGER_HPP

#include <string>
#include <list>
#include "Render/Input.hpp"

namespace ecs::network
{
enum ComponentType : char
{
    POSITION,
    ROTATION
};

class PacketManager
{
public:
    struct Component
    {
        ComponentType type;
        union {
            struct
            {
                int x;
                int y;
            } _position;

            struct
            {
                int radAngle;
            } _rotation;
        };
    };

    enum
    {
        MAX_LENGTH = 1024,
        MAX_PSEUDO_SIZE = 10,
        MAX_PLAYER = 4,
        MAX_COMPONENTS = 7,
        MAX_ROOM = 8,
        MAX_KEYS = 15
    };

    enum CMD : char
    {
        HANDSHAKE,
        ISREADY,
        JOINROOM,
        GETROOMS,
        LEAVEROOM,

        ISALIVE,
        LAUNCHGAME,
        UPDATE
    };

    struct Entity
    {
        size_t id;
        char nbrComponents;
        struct Component components[MAX_COMPONENTS];
    };

    struct PlayerInfo
    {
        bool isReady;
        char pseudo[MAX_PSEUDO_SIZE];
    };

    struct Room
    {
        bool isOpen;
        bool isStarted;
        char id;
        char nbPlayers;
        char nbPlayerMax;
        struct PlayerInfo players[MAX_PLAYER];
    };

public:
    enum
    {
        MAX_ENTITIES = MAX_LENGTH / sizeof(Entity),
        MAX_MSG_LENGTH = MAX_LENGTH / 2
    };

private:
    struct Entities
    {
        char size;
        struct Entity list[MAX_ENTITIES];
    };

    struct IsReady
    {
        bool isReady;
    };

    struct JoinRoom
    {
        char id;
    };

    struct GetRooms
    {
        char size;
        struct Room listRoom[MAX_ROOM];
    };

    struct KeysPressed
    {
        char size;
        ecs::input::Key list[MAX_KEYS];
    };

    struct Data
    {
        bool res;
        CMD typeCmd;
        int magicNumber;
        union {
            struct IsReady _isReady;
            struct JoinRoom _join;
            struct GetRooms _getRoom;
            struct Entities _entities;
            struct KeysPressed _keys;
            char _msg[MAX_MSG_LENGTH];
        };
    };
    
    union PacketData {
        char rawData[MAX_LENGTH];
        struct Data data;
    };
    
    

public:
    PacketData packet;
    /**
     * @brief Construct a new Packet Manager object
     * 
     */
    PacketManager();

    /**
     * @brief Construct a new Packet Manager object
     * 
     * @param other 
     */
    PacketManager(const PacketManager &other);

    ~PacketManager();

    /**
     * @brief Clear the packet
     * 
     */
    void clear();

    /**
     * @brief Set the Cmd in the packet
     * 
     * @param cmd 
     */
    void setCmd(const CMD cmd);

    /**
     * @brief Set the packet res info
     * 
     * @param res 
     */
    void setRes(bool res);

    /**
     * @brief Set the Join Room id
     * 
     * @param roomId 
     */
    void setJoinRoom(char roomId);

    /**
     * @brief Add an entity in the packet and returns his index, to use to add components
     * 
     * @param gameId
     * @return int : the index inside the packet, -1 if the packet is full 
     */
    int addEntity(size_t gameId);

    /**
     * @brief Add an entity in the packet and returns his index, to use to add components
     * 
     * @param gameId 
     * @return int 
     */
    int addEntity(Entity entity);

    /**
     * @brief Add position inside the entity, returns false if the number of components to add is atteint
     * 
     * @param entityIndex 
     * @param x 
     * @param y 
     * @return true 
     * @return false 
     */
    bool addPosition(int entityIndex, float x, float y);

    /**
     * @brief Add rotation inside the entity, returns false if the number of components to add is atteint
     * 
     * @param entityIndex 
     * @param angleRad 
     * @return true 
     * @return false 
     */
    bool addRotation(int entityIndex, float angleRad);

    /**
     * @brief Add a room in the packet and returns his index
     * 
     * @param room 
     * @return int , -1 if packet full
     */
    int addRoom(const Room &room);

    /**
     * @brief return if the packet is succesfull
     * 
     * @return true 
     * @return false 
     */
    bool isSuccessful() const;

    /**
     * @brief Get the Cmd object
     * 
     * @return const CMD 
     */
    CMD getCmd() const;

    /**
     * @brief Get the IsReady object
     * 
     * @return const IsReady 
     */
    const IsReady getIsReady() const;

    /**
     * @brief Get the Join Room object
     * 
     * @return const JoinRoom 
     */
    const JoinRoom getJoinRoom() const;

    /**
     * @brief Get the List Rooms object
     * 
     * @return const GetRooms 
     */
    const GetRooms getListRooms() const;

    /**
     * @brief Get the List Entities object
     * 
     * @return const Entities 
     */
    const Entities getListEntities() const;

    /**
     * @brief Get the Raw Data object
     * 
     * @return const char* 
     */
    const char *getRawData() const;

    /**
     * @brief Get the Magic Number object
     * 
     * @return char 
     */
    char getMagicNumber() const;

    /**
     * @brief Set the Msg object
     * 
     * @param msg 
     */
    void setMsg(const std::string &msg);
    
    /**
     * @brief Get the Msg object
     * 
     * @return std::string 
     */
    const std::string getMsg();

    /**
     * @brief Get the Keys object
     * 
     * @return const KeysPressed 
     */
    const KeysPressed getKeys() const;

    /**
     * @brief Add a key to the packet
     * 
     * @param keyPressed 
     * @return int : index  of the key add, -1 if full
     */
    int addKey(const ecs::input::Key keyPressed);
};

} // namespace ecs::network

#endif