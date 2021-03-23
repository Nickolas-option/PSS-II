#include <iostream>
#include <string>

using namespace std;

#include "Room.h"

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
    cout << "Hi! Would you like to see test cases for HW2? "
            "Please, type 0(false) or 1(true). Test for HW3 will be displayed anyway.\n";
    int userInput;
    cin >> userInput;
    if (userInput == 1) {
        cout << "\nTests for HW2:\n\n";
        cout << "\n###Trying to enter Director Room\n\n";
        cout << directorRoom.tryToEnter(NikitaAdmin);
        cout << directorRoom.tryToEnter(Tormasov);
        cout << directorRoom.tryToEnter(ProfShilov);
        cout << directorRoom.tryToEnter(Lab2);
        cout << directorRoom.tryToEnter(Stud2);

        cout << "\n\n###Trying to enter Conference Room\n\n";
        cout << room3.tryToEnter(NikitaAdmin);
        cout << room3.tryToEnter(Tormasov);
        cout << room3.tryToEnter(ProfShilov);
        cout << room3.tryToEnter(Lab2);
        cout << room3.tryToEnter(Stud2);

        cout << "\n\n###Trying to enter Lecture \n\n";
        cout << room4.tryToEnter(NikitaAdmin);
        cout << room4.tryToEnter(Tormasov);
        cout << room4.tryToEnter(ProfShilov);
        cout << room4.tryToEnter(Lab2);
        cout << room4.tryToEnter(Stud2);
        cout << '\n';

        cout << room3.tryToEnter(Stud2);
        NikitaAdmin.grantAccess(Stud2, yellowLevel);
        cout << "###Now admin with give " + Stud2.getName() + " access of yellow level...\n";
        cout << room3.tryToEnter(Stud2);
    }
//New HW3 tests:
    cout << "\nTests for HW3:\n";
    Emergency::initializeEmergency();

    auto guest = Guest("Irina");
    auto conference123 = ConferenceRoom(123);
    auto conference213 = ConferenceRoom(213);
    auto lecture523 = LectureRoom(523);
    cout << "\n" << lecture523.tryToEnter(guest) << "\n" << conference123.tryToEnter(guest) << "\n";
    cout << conference213.tryToEnter(guest) << "\n";

    NikitaAdmin.grantAccess(guest, 213);
    cout << "Admin granted personal access to the room\n";
    cout << conference213.tryToEnter(guest) << "\n";
    cout << "Admin removed personal access to the room\n";
    NikitaAdmin.removeAccess(guest, 213);
    cout << conference213.tryToEnter(guest) << "\n";

    cout << conference213.tryToEnter(guest);
    Emergency::startEmergency();
    cout << (Emergency::isEmergency() ? "Emergency! RUN!\n" : "No emergency, keep calm, drink tea.\n");
    cout << conference213.tryToEnter(guest);
    Emergency::finishEmergency(guest);
    cout << "Guest: 'I accidentally activated emergency, sorry'\n";
    cout << "Admin: 'That's bad, I will fix this'\n";
    Emergency::finishEmergency(NikitaAdmin);
    cout << (Emergency::isEmergency() ? "Emergency! RUN!\n" : "No emergency, keep calm, drink tea.\n");

    return 0;
}
