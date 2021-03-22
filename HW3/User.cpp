//
// Created by nikae on 07.03.2021.
//

#include <string>
#include "User.h"


AccessLevel User::getCard() {
    return this->card;
}

string User::getname() {
    return name;
}

Professor::Professor(string name) {
    this->name = name;
    this->card = yellowLevel;
}

Professor::Professor(string name, string joke) : Professor(name) {
    this->joke = joke;
}

string Professor::tellJoke() {
    return joke + "\n";
};


Student::Student(string name) {
    this->name = name;
    this->card = noLevel;
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
    this->card = redLevel;
}


LabEmployee::LabEmployee(string name) {
    this->name = name;
    this->card = greenLevel;
}

Admin::Admin(string name) {
    this->name = name;
    this->card = redLevel;
}

void Admin::grantAccess(User *person, AccessLevel level) {
    person->card = level;
}