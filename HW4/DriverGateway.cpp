using namespace std;

#include "iostream"
#include "DriverGateway.h"


//vector<Order> DriverGateway::seeOrderHistory(DriverApp *Driver) {
//    return driversOrderHistories[driversList[(*Driver)]];
//}


void DriverGateway::seeCar(DriverApp *Driver) {
    cout << Car::printCarType(Driver->car->Type) + "\n";
    cout << "White Chevrolet\n";
}