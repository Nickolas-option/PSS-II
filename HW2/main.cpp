#include <iostream>

using namespace std;

enum AccessLevel {
    noLevel = 0,
    greenLevel = 1,
    yellowLevel = 2,
    redLevel = 3,
};

class User {
public:
    AccessLevel getCard() {
        return this->card;
    }

    string getname() {
        return name;
    }

protected:
    AccessLevel card;
    string name;

    friend class Admin;
};

class Professor : public User {
public:
    Professor(string name) {
        this->name = name;
        this->card = yellowLevel;
    }

    Professor(string name, string joke) : Professor(name) {
        this->joke = joke;
    }

    ~Professor() = default;

    string tellJoke() {
        return joke + "\n";
    };
private:
    string joke = "No joke yet\n";
    string universityPosition = "Prof.";
};

class Student : public User {
public:
    Student(string name) {
        this->name = name;
        this->card = noLevel;
    }

    Student(string name, int roomNumber) : Student(name) {
        dormRoomNumber = roomNumber;
    }

    string complain(string subject = "stipa") {
        if (subject == "stipa") {
            return "Why stipa is so small? :(\n";
        } else {
            return name + ": I am not happy with " + subject + "!\n";
        }
    }

    string IntroduceYourself() {
        return "I am " + name + ". I live in campus room number " + to_string(dormRoomNumber) + "\n";
    }

private:
    int dormRoomNumber = 0;
    string universityPosition = "a student";
};

class Director : public User {
public:
    Director(string name) {
        this->name = name;
        this->card = redLevel;
    }

private:
    string universityPosition = "the director";
};

class LabEmployee : public User {
public:
    LabEmployee(string name) {
        this->name = name;
        this->card = greenLevel;
    }

private:
    string universityPosition = "a lab employee";
};

class Admin : public User {
public:
    Admin(string name) {
        this->name = name;
        this->card = redLevel;
    }

    void grantAccess(User* person, AccessLevel level) {
        person->card = level;
    }

private:
    string universityPosition = "an admin";
};

class Room {
public:
    Room() = default;

    ~Room() = default;

    Room(int number) {
        roomNumber = number;
    }

    string getRoomNumber() {
        return to_string(roomNumber);
    }

    string tryToEnter(User person) {
        if (person.getCard() >= accessNeeded) {
            return person.getname() + " entered the room number " + to_string(roomNumber) + "\n";
        }
        return person.getname() + " tried to enter the room number "
               + to_string(roomNumber) + ", but got no access\n";
    }

protected:
    AccessLevel accessNeeded;
    int roomNumber;
};

class LectureRoom : public Room {
public:
    LectureRoom(int number, AccessLevel accessNeeded = noLevel) {
        this->roomNumber = number;
        this->accessNeeded = accessNeeded;
    }
};

class ConferenceRoom : public Room {
public:
    ConferenceRoom(int number, AccessLevel accessNeeded = yellowLevel) {
        this->roomNumber = number;
        this->accessNeeded = accessNeeded;
    }
};

class Cabinet : public Room {
public:
    Cabinet(int number, AccessLevel accessNeeded = noLevel) {
        this->roomNumber = number;
        this->accessNeeded = accessNeeded;
    }
};

class DirectorCabinet : public Room {
public:
    DirectorCabinet(int number, AccessLevel accessNeeded = redLevel) {
        this->roomNumber = number;
        this->accessNeeded = accessNeeded;
    }

};


int main() {
    //1 director, 2 admins, 4 professors, 8 employees, 16 students
    auto Tormasov = Director("Alexander Tormasov");

    auto NikitaAdmin = Admin("Nikita");
    auto MikeAdmin = Admin("Mikhail");

    auto ProfZouev = Professor("Eugene Zouev");
    auto ProfShilov = Professor("Nikolay Shilov");
    auto ProfKonyukhov = Professor("Ivan Konyukhov");
    auto ProfKhan = Professor("Adil Khan");

    auto Lab1 = LabEmployee("Alexandr Klimchik");
    auto Lab2 = LabEmployee("Artem Kruglov");
    auto Lab3 = LabEmployee("Sergei Savin");
    auto Lab4 = LabEmployee("Andrey Sadovykh");
    auto Lab5 = LabEmployee("Stanislav Protasov");
    auto Lab6 = LabEmployee("Alma Oracevic");
    auto Lab7 = LabEmployee("Ahsan Kazmi");
    auto Lab8 = LabEmployee("Igor Gaponov");

    auto Stud1 = Student("Asem Abdelhady");
    auto Stud2 = Student("Karina Tyulebaeva");
    auto Stud3 = Student("Khush Patel", 320);
    auto Stud4 = Student("Zeiin Kanabekov", 201);
    auto Stud5 = Student("Evgenii Evlampev", 301);
    auto Stud6 = Student("Iskander Nafikov");
    auto Stud7 = Student("Makar Vavilov", 305);
    auto Stud8 = Student("George Dmitriev", 303);
    auto Stud9 = Student("Slava Koshman", 302);
    auto Stud10 = Student("Mark Zakharov", 302);
    auto Stud11 = Student("Ilya Siluyanov", 202);
    auto Stud12 = Student("Eduard Zaripov", 303);
    auto Stud13 = Student("Artur Eremov");
    auto Stud14 = Student("Anastasiia Kuklina", 315);
    auto Stud15 = Student("Artyom Chernitsa");
    auto Stud16 = Student("Ignat Petrov");


    auto room1 = Cabinet(201);
    auto directorRoom = DirectorCabinet(205);
    auto room3 = ConferenceRoom(405);
    auto room4 = LectureRoom(105);
    auto room5 = LectureRoom(108);
    auto room6 = Cabinet(408);
    auto room7 = Cabinet(409);

    cout << "Trying to enter Director Room\n";
    cout << directorRoom.tryToEnter(NikitaAdmin);
    cout << directorRoom.tryToEnter(Tormasov);
    cout << directorRoom.tryToEnter(ProfShilov);
    cout << directorRoom.tryToEnter(Lab2);
    cout << directorRoom.tryToEnter(Stud2);

    cout << "\nTrying to enter Conference Room\n";
    cout << room3.tryToEnter(NikitaAdmin);
    cout << room3.tryToEnter(Tormasov);
    cout << room3.tryToEnter(ProfShilov);
    cout << room3.tryToEnter(Lab2);
    cout << room3.tryToEnter(Stud2);

    cout << "\nTrying to enter Lecture \n";
    cout << room4.tryToEnter(NikitaAdmin);
    cout << room4.tryToEnter(Tormasov);
    cout << room4.tryToEnter(ProfShilov);
    cout << room4.tryToEnter(Lab2);
    cout << room4.tryToEnter(Stud2);

    cout << room3.tryToEnter(Stud2);
    NikitaAdmin.grantAccess(&Stud2,yellowLevel);
    cout << room3.tryToEnter(Stud2);


    return 0;
}
