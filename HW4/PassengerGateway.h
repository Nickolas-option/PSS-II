//
// Created by nikae on 14.04.2021.
//

#ifndef WENDEX_PASSENGERGATEWAY_H
#define WENDEX_PASSENGERGATEWAY_H

#endif //WENDEX_PASSENGERGATEWAY_H

#include "vector"
#include "string"
#include "Car.h"
#include "Order.h"
#include "PassengerApp.h"

using namespace std;

class PassengerGateway {
private:
    static vector<vector<Order>> PassengersOrderHistories;
    static vector<int> PassengersList;

    std::vector<Order> seeOrderHistory(PassengerApp *Passenger);

    std::vector<std::string> seeUpdatePaymentMethods(PassengerApp *Passenger);

    std::vector<std::string> seeUpdatePaymentMethods(PassengerApp *Passenger, std::vector<std::string>);

    std::vector<std::string> seeUpdatePinnedAddresses(PassengerApp *Passenger);

    std::vector<std::string> seeUpdatePinnedAddresses(PassengerApp *Passenger, std::vector<std::string>);

    std::pair<int, int> CheckRide(PassengerApp *Passenger, std::string, std::string, CarType);

    void OrderRide(PassengerApp *Passenger, std::string, std::string, CarType);

    std::string ChangePayMethodTemp(PassengerApp *Passenger, std::string);

    std::pair<int, int> WhereIsCar(PassengerApp *Passenger);

    void GetBill(PassengerApp *Passenger);

    friend PassengerApp;
};