#ifndef R_TYPE_ROOM_HPP
#define R_TYPE_ROOM_HPP

#include <cstddef>

class Room {
    private:

    size_t _id;
    bool _isOpen;

    public:
    Room(const size_t &id);

    virtual ~Room();

    size_t getId() const;

    void setId(size_t id);
    bool isIsOpen() const;

    void setIsOpen(bool isOpen);

};

#endif //R_TYPE_ROOM_HPP
