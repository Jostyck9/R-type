/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** ServerSession.hpp
*/

#ifndef SESSION_HPP__
#define SESSION_HPP__

#include "PacketManager.hpp"
#include <Room/RoomManager.hpp>
#include "ISession.hpp"

namespace ecs::network {
    class ServerSession
        : public std::enable_shared_from_this<ServerSession>,
            public ecs::network::ISession {
        private:
        udp::endpoint &_sender_endpoint;
        udp::socket &_socket;
        RoomManager &_roomManager;
        ecs::network::PacketManager _packet;
        //ecs::network::PacketManager _packet;

        struct SessionInfo {
            bool isConnected;
            bool isInRoom;
            size_t roomId;
        };
        SessionInfo _info;

        using ptrFunc = bool (ecs::network::ServerSession::*)();
        std::map<ecs::network::PacketManager::CMD, ptrFunc> _functionsProtocol;


        private:

        enum {
            max_length = 1024
        };
        size_t recv;
        public:

        ServerSession(udp::socket &_socket, udp::endpoint &senderEndpoint, RoomManager &roomManager);
        ~ServerSession();

        void do_write(const char data[max_length]) override;

        void handle_write(boost::system::error_code ec, std::size_t length) override;

        void manage_data(const char rawData[max_length]) override;

        const SessionInfo &getInfo() const;

        bool isPacketValid();
        bool setMsgPacket(const std::string &msg);

        bool manageLeaveRoom();
        bool manageJoinRoom();
        bool manageGetRooms();
        bool manageHandShake();
        bool manageIsReady();
        bool manageLaunchGame();
        bool manageUpdate();
    };
}
#endif //SESSION_HPP__