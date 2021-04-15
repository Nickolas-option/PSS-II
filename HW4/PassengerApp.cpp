//
// Created by nikae on 14.04.2021.
//

#include <iostream>
#include "PassengerApp.h"
#include "Order.h"
class PassengerGateway;
PassengerApp::PassengerApp(string name, string password, int id) {
    this->name = name;
    this->password = password;
    this->id = id;
    PassengerGateway::PassengersList.push_back(id);
    PassengerGateway::PassengersOrderHistories.push_back(vector<Order>{});
}

void PassengerApp::connectToApp(string password) {
    if (password == this->password) {
        std::cout << "Successful authorization.";
    } else {
        std::cout << "Wrong password. NULL pointer returned";
    }
}
