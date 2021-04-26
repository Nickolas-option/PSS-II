#include <iostream>
#include "PassengerApp.h"
#include "PassengerGateway.h"
#include "Car.h"
#include "DriverApp.h"
#include "DriverGateway.h"
#include "Order.h"

using namespace std;


int main() {
    auto Pass1 = PassengerApp("Tim", "TIM2020", 1);
    Pass1.connectToApp("TIM2020");
    auto passengerSystem = PassengerGateway();
    cout << "id of the first passenger is " + to_string(PassengerGateway::PassengersList[0]) + "\n";
    passengerSystem.CheckRide(&Pass1, "Mexico", "Tokyo", Car::Econom);
    auto Rider1 = DriverApp("Nick", "Nick2020", 1);
    Rider1.connectToApp("Nick2020");
    auto driverSystem = DriverGateway();

    return 0;
}
