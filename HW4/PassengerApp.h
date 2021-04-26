
#ifndef WENDEX_PASSENGERAPP_H
#define WENDEX_PASSENGERAPP_H

#include <string>
#include "vector"
#include <iostream>

using namespace std;


class PassengerApp {
public:
    PassengerApp(string name, string password, int id);

    int getId();

    void connectToApp(string password);

private:
    int id;
    string name;
    vector<string> paymentMethods;
    vector<string> pinnedAddresses;
    string password;

    friend class PassengerGateway;

    friend class DriverGateway;
};

#endif //WENDEX_PASSENGERAPP_H
