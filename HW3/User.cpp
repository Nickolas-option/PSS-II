#include <string>
#include <vector>
#include <set>
#include "User.h"


Card &User::getCard() {
    return this->card;
}

string User::getName() {
    return name;
}


Professor::Professor(string name) {
    this->name = name;
    this->card.cardLevel = yellowLevel;
}

Professor::Professor(string name, string joke) : Professor(name) {
    this->joke = joke;
}

string Professor::tellJoke() {
    return joke + "\n";
};


Student::Student(string name) {
    this->name = name;
    this->card.cardLevel = blueLevel;
}

Student::Student(string name, int roomNumber) : Student(name) {
    dormRoomNumber = roomNumber;
}

string Student::complain(string subject = "stipa") {
    if (subject == "stipa") {
        return "Why stipa is so small? :(\n";
    } else {
        return name + ": I am not happy with " + subject + "!\n";
    }
}

string Student::IntroduceYourself() {
    return "I am " + name + ". I live in campus room number " + to_string(dormRoomNumber) + "\n";
}


Director::Director(string name) {
    this->name = name;
    this->card.cardLevel = redLevel;
}


LabEmployee::LabEmployee(string name) {
    this->name = name;
    this->card.cardLevel = greenLevel;
}


Admin::Admin(string name) {
    this->name = name;
    this->card.cardLevel = redLevel;
}

void Admin::grantAccess(User &person, AccessLevel level) {
    person.card.cardLevel = level;
}

void Admin::grantAccess(User &person, int roomNumber) {
    person.card.availableRooms.insert(roomNumber);
}

void Admin::removeAccess(User &person, int roomNumber) {
    person.card.availableRooms.erase(roomNumber);
}

Guest::Guest(string name) {
    this->name = name;
}

