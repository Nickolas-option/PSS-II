//
// Created by nikae on 07.03.2021.
//
#ifndef HW2_USER_H
#define HW2_USER_H

#endif //HW2_USER_H
using namespace std;

enum AccessLevel {
    noLevel = 0,
    greenLevel = 1,
    yellowLevel = 2,
    redLevel = 3,
};

class User {
public:
    AccessLevel getCard();

    string getname();

protected:
    AccessLevel card;
    string name;

    friend class Admin;
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

    void grantAccess(User *person, AccessLevel level);

private:
    string universityPosition = "an admin";
};