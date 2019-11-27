/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** PacketManager.hpp
*/

#ifndef PACKETMANAGER_HPP
#define PACKETMANAGER_HPP

#include <list>

namespace ecs::network
{
enum ComponentType : char
{
    POSITION,
    ROTATION
};

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

struct Entity
{
    size_t id;
    std::list<Component> components;
};

class PacketManager
{
public:
    enum
    {
        MAX_LENGTH = 1024,
        MAX_COMPONENTS = 7,
    };

private:
    struct EntityPacket
    {
        size_t id;
        Component components[MAX_COMPONENTS];
    };

public:
    enum
    {
        MAX_ENTITIES = MAX_LENGTH / sizeof(Entity)
    };

private:
    struct Data
    {
        char nbrEntities;
        EntityPacket entities[MAX_ENTITIES];
    };

public:
    struct PacketData
    {
        union {
            char rawData[MAX_LENGTH];
            Data data;
        };
    } packet;

    PacketManager();
    ~PacketManager();
};

} // namespace ecs::network

#endif