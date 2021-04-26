#include <iostream>
#include "Car.h"

ComfortCar::ComfortCar(int bottle) {
    freeBottleOfWater = bottle;
    Type = Comfort;
}

EconomyCar::EconomyCar() {
    Type = Econom;
}

ComfortPlusCar::ComfortPlusCar() {
    Type = ComfortPlus;
}

BusinessCar::BusinessCar() {
    Type = Business;
}

void BusinessCar::parkRightInFrontOfTheEntrance() {
    cout << "Parked right";
}

string Car::printCarType(Car::CarType carType) {
    if (carType == CarType::Business) {
        return "Business";
    } else if (carType == CarType::ComfortPlus) {
        return "ComfortPlus";
    } else if (carType == CarType::Comfort) {
        return "Comfort";
    } else {
        return "Econom";
    };
}
