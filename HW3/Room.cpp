#include <string>
#include <cmath>
#include "Room.h"


[[maybe_unused]] Room::Room(int number) {
    roomNumber = number;
}

string Room::getRoomNumber() const {
    return to_string(roomNumber);
}

string Room::tryToEnter(User &person) {
    Card &personCard = person.getCard();
    auto &personLevel = personCard.cardLevel;
    auto &personRooms = personCard.availableRooms;
    bool shouldOpenRoom = Emergency::isEmergency() ||
                          personLevel >= checkLevel() ||
                          personRooms.find(roomNumber) != personRooms.cend();
    if (shouldOpenRoom) {
        return person.getName() + " entered the room number " + to_string(roomNumber) + "\n";
    }
    return person.getName() + " tried to enter the room number "
           + to_string(roomNumber) + ", but got no access\n";
}

AccessLevel Room::checkLevel() {
    return accessNeeded;
}


LectureRoom::LectureRoom(int number, AccessLevel accessNeeded) {
    this->roomNumber = number;
    this->accessNeeded = accessNeeded;
}

ConferenceRoom::ConferenceRoom(int number, AccessLevel accessNeeded) {
    this->roomNumber = number;
    this->accessNeeded = accessNeeded;
}

AccessLevel ConferenceRoom::checkLevel() {
    // Finding first digit of roomNumber
    int digits = (int) log10(roomNumber);
    int firstDigit = (int) (roomNumber / pow(10, digits));
    if (firstDigit == 1) {
        return blueLevel;
    }
    return accessNeeded;
}

Cabinet::Cabinet(int number, AccessLevel accessNeeded) {
    this->roomNumber = number;
    this->accessNeeded = accessNeeded;
}

DirectorCabinet::DirectorCabinet(int number, AccessLevel accessNeeded) {
    this->roomNumber = number;
    this->accessNeeded = accessNeeded;
}
