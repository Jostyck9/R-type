/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** PacketManager.hpp
*/

#ifndef PACKETMANAGER_HPP
#define PACKETMANAGER_HPP

#include <iostream>

class PacketManager
{
public:
    enum componentType : char
    {
        POSITION,
        ROTATION
    };

private:
    struct Component
    {
        componentType type;
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

public:
    enum
    {
        MAX_LENGTH = 1024,
        MAX_COMPONENTS = 7,
    };

private:
    struct Entity
    {
        size_t id;
        PacketManager::Component components[MAX_COMPONENTS];

    } test;

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

#endif