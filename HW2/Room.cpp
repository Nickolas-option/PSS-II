//
// Created by nikae on 08.03.2021.
//


#include <string>
#include "Room.h"


Room::Room(int number) {
    roomNumber = number;
}

string Room::getRoomNumber() {
    return to_string(roomNumber);
}

string Room::tryToEnter(User person) {
    if (person.getCard() >= accessNeeded) {
        return person.getname() + " entered the room number " + to_string(roomNumber) + "\n";
    }
    return person.getname() + " tried to enter the room number "
           + to_string(roomNumber) + ", but got no access\n";
}


LectureRoom::LectureRoom(int number, AccessLevel accessNeeded) {
    this->roomNumber = number;
    this->accessNeeded = accessNeeded;
}

ConferenceRoom::ConferenceRoom(int number, AccessLevel accessNeeded) {
    this->roomNumber = number;
    this->accessNeeded = accessNeeded;
}

Cabinet::Cabinet(int number, AccessLevel accessNeeded) {
    this->roomNumber = number;
    this->accessNeeded = accessNeeded;
}

DirectorCabinet::DirectorCabinet(int number, AccessLevel accessNeeded) {
    this->roomNumber = number;
    this->accessNeeded = accessNeeded;
}
