//
// Created by nikae on 08.03.2021.
//

#include "User.h"

#ifndef HW2_ROOM_H
#define HW2_ROOM_H

#endif //HW2_ROOM_H

class Room {
public:
    Room() = default;

    ~Room() = default;

    Room(int number);

    string getRoomNumber();

    string tryToEnter(User person);

protected:
    AccessLevel accessNeeded;
    int roomNumber;
};

class LectureRoom : public Room {
public:
    LectureRoom(int number, AccessLevel accessNeeded = noLevel);
};

class ConferenceRoom : public Room {
public:
    ConferenceRoom(int number, AccessLevel accessNeeded = yellowLevel);
};

class Cabinet : public Room {
public:
    Cabinet(int number, AccessLevel accessNeeded = noLevel);
};

class DirectorCabinet : public Room {
public:
    DirectorCabinet(int number, AccessLevel accessNeeded = redLevel);
};