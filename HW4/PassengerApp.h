//
// Created by nikae on 14.04.2021.
//

#include <string>
#include "vector"

#ifndef WENDEX_PASSENGERAPP_H
#define WENDEX_PASSENGERAPP_H

#endif //WENDEX_PASSENGERAPP_H
using namespace std;

class PassengerApp {
public:
    PassengerApp(string name, string password, int id);

    void connectToApp(string password);

private:
    int id;
    string name;
    vector<string> paymentMethods;
    vector<string> pinnedAddresses;
    string password;

};