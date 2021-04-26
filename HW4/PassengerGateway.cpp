#include "PassengerGateway.h"
#include "DriverApp.h"
#include "DriverGateway.h"
#include "Car.h"

using namespace std;

vector<Order> PassengerGateway::seeOrderHistory(PassengerApp *Passenger) {
    return PassengersOrderHistories[PassengersList[Passenger->getId()]];
}

vector<string> PassengerGateway::seeUpdatePaymentMethods(PassengerApp *Passenger) {
    return Passenger->paymentMethods;
}

vector<string> PassengerGateway::seeUpdatePaymentMethods(PassengerApp *Passenger, vector<string> newMethods) {
    Passenger->paymentMethods = newMethods;
    return Passenger->paymentMethods;
}

std::vector<std::string> PassengerGateway::seeUpdatePinnedAddresses(PassengerApp *Passenger) {
    return Passenger->pinnedAddresses;
}

std::vector<std::string>
PassengerGateway::seeUpdatePinnedAddresses(PassengerApp *Passenger, vector<std::string> newPinnedAddresses) {
    Passenger->pinnedAddresses = newPinnedAddresses;
    return Passenger->pinnedAddresses;
}

void PassengerGateway::CheckRide(PassengerApp *Passenger, string from, string to, Car::CarType
carType) {
    int price = rand() % 100;
    cout << "Ride is available, the price will be " + to_string(price) +
            "$ for going from " + from + " to " + to + " on a " +
            Car::printCarType(carType) + " car.\n";
    cout << "Would you like to order? 1 - yes. 0 - no.\n";
    bool shouldOrder = false;
    cin >> shouldOrder;
    if (shouldOrder) {
        OrderRide(Passenger, from, to, carType, price);
    } else {
        cout << "Alright then, have a good day!\n";
    }
}

void PassengerGateway::OrderRide(PassengerApp *Passenger, string from, string to, Car::CarType carType, int price) {
    if (DriverGateway::driversList.empty()) {
        cout << "No drivers available, sorry.\n";
        return;
    }
    DriverApp *randomDriver = reinterpret_cast<DriverApp *>(&DriverGateway::driversList[0]);
    int index = 0;
    while (randomDriver->getStatus() != available and index != DriverGateway::driversList.size() - 1) {
        index++;
        randomDriver = DriverGateway::driversList[index];
    }
    PassengersOrderHistories[PassengersList[Passenger->getId()]].push_back(Order(from, to, randomDriver->name,
                                                                                 Passenger->name, price));
}

void PassengerGateway::GetBill(PassengerApp *Passenger) {
    Order lastOrder = PassengersOrderHistories[PassengersList[Passenger->getId()]].back();
    cout << lastOrder.passengerName + " was serviced by " + lastOrder.driverName + " from "
            + lastOrder.from + " to " + lastOrder.to + " for the price of " + to_string(lastOrder.price) + "$.\n";
}

std::pair<int, int> PassengerGateway::WhereIsCar(PassengerApp *Passenger) {
    return make_pair(rand() % 200, rand() % 200);
}


