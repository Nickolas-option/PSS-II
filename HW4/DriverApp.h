//
// Created by nikae on 14.04.2021.
//

#ifndef WENDEX_DRIVERAPP_H
#define WENDEX_DRIVERAPP_H

#endif //WENDEX_DRIVERAPP_H

#include "string"
#include "vector"

using namespace std;

class Car;

enum Status {
    workingAndFree,
    workingAndBusy,
    notWorking
};

class DriverApp {
public:
    void connectToApp(string password); //TODO implement authorization

private:
    string name;
    string rating;
    vector<string> orderHistory;
    Car *car;
    Status status;
};
