#ifndef WENDEX_DRIVERAPP_H
#define WENDEX_DRIVERAPP_H

#include "string"
#include "vector"
#include "Car.h"

using namespace std;

enum Status {
    available,
    busy,
    notWorking
};

class DriverApp {
public:
    DriverApp(string name, string password, int id);

    void connectToApp(string password);

    Status getStatus();

private:
    string name;
    int id;
    int rating;
    vector<string> orderHistory;
    Car *car;
    Status status;
    string password;

    friend class DriverGateway;

    friend class PassengerGateway;
};

#endif //WENDEX_DRIVERAPP_H