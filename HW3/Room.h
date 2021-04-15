#include "Emergency.h"
#ifndef HW3_ROOM_H
#define HW3_ROOM_H

#endif //HW3_ROOM_H

class Room {
public:
    Room() = default;

    ~Room() = default;

    [[maybe_unused]] explicit Room(int number);

    string getRoomNumber() const;

    string tryToEnter(User &person);

protected:
    AccessLevel accessNeeded;
    int roomNumber;

    virtual AccessLevel checkLevel();
};

class LectureRoom : public Room {
public:
    LectureRoom(int number, AccessLevel accessNeeded = blueLevel);
};

class ConferenceRoom : public Room {
public:
    ConferenceRoom(int number, AccessLevel accessNeeded = yellowLevel);

private:
    AccessLevel checkLevel();
};

class Cabinet : public Room {
public:
    Cabinet(int number, AccessLevel accessNeeded = greenLevel);
};

class DirectorCabinet : public Room {
public:
    DirectorCabinet(int number, AccessLevel accessNeeded = redLevel);
};