#ifndef HW3_USER_H
#define HW3_USER_H
#endif //HW3_USER_H

#include <set>
using namespace std;

enum AccessLevel {
    tempEmergencyAccess = -1,
    blueLevel = 0,
    greenLevel = 1,
    yellowLevel = 2,
    redLevel = 3,
};

struct Card {
    set<int> availableRooms;
    AccessLevel cardLevel;
};

class User {
public:
    Card &getCard();

    string getName();

protected:
    Card card;
    string name;

    friend class Admin;
};

class Guest : public User {
public:
    Guest(string name);

    ~Guest() = default;

private:
    string universityPosition = "Guest";
};

class Professor : public User {
public:
    Professor(string name);

    Professor(string name, string joke);

    ~Professor() = default;

    string tellJoke();

private:
    string joke = "No joke yet\n";
    string universityPosition = "Prof.";
};

class Student : public User {
public:
    Student(string name);

    Student(string name, int roomNumber);

    string complain(string subject);

    string IntroduceYourself();

private:
    int dormRoomNumber = 0;
    string universityPosition = "a student";
};

class Director : public User {
public:
    Director(string name);

private:
    string universityPosition = "the director";
};

class LabEmployee : public User {
public:
    LabEmployee(string name);

private:
    string universityPosition = "a lab employee";
};

class Admin : public User {
public:
    Admin(string name);

    void grantAccess(User &person, AccessLevel level);

    void grantAccess(User &person, int roomNumber);

    void removeAccess(User &person, int roomNumber);

private:
    string universityPosition = "an admin";
};