#include "DriverApp.h"
#include "iostream"

using namespace std;

Status DriverApp::getStatus() {
    return status;
}

DriverApp::DriverApp(string name, string password, int id) {
    this->name = name;
    this->status = available;
    this->rating = 5;
    this->id = id;
    this->password = password;
}

void DriverApp::connectToApp(string password) {
    if (password == this->password) {
        cout << "Succsesful authorization.\n";
    } else {
        cout << "Wrong password\n";
    }
}
