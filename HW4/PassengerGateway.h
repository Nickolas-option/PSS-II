
#ifndef WENDEX_PASSENGERGATEWAY_H
#define WENDEX_PASSENGERGATEWAY_H

#include "vector"
#include "string"
#include "Order.h"
#include "PassengerApp.h"
#include "Car.h"

using namespace std;

class PassengerGateway {
public:
    inline static vector<vector<Order>> PassengersOrderHistories {};
    inline static vector<int> PassengersList {};

    std::vector<Order> seeOrderHistory(PassengerApp *Passenger);

    std::vector<std::string> seeUpdatePaymentMethods(PassengerApp *Passenger);

    std::vector<std::string> seeUpdatePaymentMethods(PassengerApp *Passenger, std::vector<std::string> newMethods);

    std::vector<std::string> seeUpdatePinnedAddresses(PassengerApp *Passenger);

    std::vector<std::string> seeUpdatePinnedAddresses(PassengerApp *Passenger, std::vector<std::string>
            newPinnedAddresses);

    void CheckRide(PassengerApp *Passenger, std::string from, std::string to, Car::CarType);

    void OrderRide(PassengerApp *Passenger, std::string from, std::string to, Car::CarType, int price);

    std::string ChangePayMethodTemp(PassengerApp *Passenger, std::string TempPayMethod);

    std::pair<int, int> WhereIsCar(PassengerApp *Passenger);

    void GetBill(PassengerApp *Passenger);

    friend PassengerApp;
};
#endif //WENDEX_PASSENGERGATEWAY_H

