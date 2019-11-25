#include "Room.hpp"

Room::Room(const size_t &id) : _id(id), _isOpen(true)
{
}

Room::~Room()
{
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
