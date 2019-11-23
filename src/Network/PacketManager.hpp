/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** PacketManager.hpp
*/

#ifndef PACKETMANAGER_HPP
#define PACKETMANAGER_HPP

class PacketManager {
public:
    enum state {
        hanshake,
        command,
        update,
    };
    struct data
    {
        union
        {
            char rawData[1024];
            struct {
                state status;
                int index;
                char name[20];
            } information;
        };
    };
    PacketManager();
    ~PacketManager();
};

#endif