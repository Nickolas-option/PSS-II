
#include "PassengerApp.h"
#include "PassengerGateway.h"

PassengerApp::PassengerApp(string name, string password, int id) {
    this->name = name;
    this->password = password;
    this->id = id;
    PassengerGateway::PassengersList.push_back(id);
    PassengerGateway::PassengersOrderHistories.push_back(vector<Order>{});
}

void PassengerApp::connectToApp(string password) {
    if (password == this->password) {
        std::cout << "Successful authorization.\n";
    } else {
        std::cout << "Wrong password. NULL pointer returned\n";
    }
}

int PassengerApp::getId() {
    return this->id;
}
