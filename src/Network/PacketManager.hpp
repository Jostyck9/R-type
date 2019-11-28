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
        MAX_COMPONENTS = 7,
    };

    struct Entity
    {
        size_t id;
        char nbrComponents;
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
        Entity entities[MAX_ENTITIES];
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