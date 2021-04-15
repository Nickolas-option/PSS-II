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
    auto system = PassengerGateway();
    cout << "id of the first passenger is " + to_string(PassengerGateway::PassengersList[0]);
    return 0;
}
