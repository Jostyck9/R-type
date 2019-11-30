/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** testPacketManager.cpp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "PacketManager.hpp"

Test(PacketManager, setCMD)
{
    ecs::network::PacketManager packet;

    packet.setCmd(ecs::network::PacketManager::CMD::GETROOMS);
    cr_assert_eq(packet.getCmd(), ecs::network::PacketManager::CMD::GETROOMS);
}

Test(PacketManager, setMsg)
{
    ecs::network::PacketManager packet;
    std::string msg = "This is my msg !";

    packet.setMsg(msg);
    cr_assert_eq(packet.getMsg(), msg);
}

Test(PacketManager, setSuccess)
{
    ecs::network::PacketManager packet;

    cr_assert_eq(packet.isSuccessful(), true);
    packet.setRes(false);
    cr_assert_eq(packet.isSuccessful(), false);
}

Test(PacketManager, AddEntity)
{
    ecs::network::PacketManager packet;
    ecs::network::PacketManager::Entity entity;

    entity.id = 3;
    entity.nbrComponents = 2;
    entity.components[0].type = ecs::network::POSITION;
    entity.components[0]._position.x = 20;
    entity.components[0]._position.y = 30;

    entity.components[1].type = ecs::network::ROTATION;
    entity.components[1]._rotation.radAngle = 5;
    cr_assert_eq(packet.getListEntities().size, 0);
    packet.addEntity(entity);
    cr_assert_eq(packet.getListEntities().size, 1);
    cr_assert_eq(packet.getListEntities().list[0].id, 3);
    cr_assert_eq(packet.getListEntities().list[0].nbrComponents, 2);
    cr_assert_eq(packet.getListEntities().list[0].components[0].type, ecs::network::POSITION);
    cr_assert_eq(packet.getListEntities().list[0].components[0]._position.x, 20);
    cr_assert_eq(packet.getListEntities().list[0].components[0]._position.y, 30);
    cr_assert_eq(packet.getListEntities().list[0].components[1].type, ecs::network::ROTATION);
    cr_assert_eq(packet.getListEntities().list[0].components[1]._rotation.radAngle, 5);
    packet.clear();
    for (int i = 0; i < ecs::network::PacketManager::MAX_ENTITIES; i++)
    {
        cr_assert_neq(packet.addEntity(entity), -1);
    }
    cr_assert_eq(packet.addEntity(entity), -1);
}