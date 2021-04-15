//
// Created by nikae on 14.04.2021.
//

#include "Car.h"

ComfortCar::ComfortCar(int bottle) {
    freeBottleOfWater = bottle;
    Type = Comfort;
}

EconomyCar::EconomyCar() {
    Type = Economy;
}

ComfortPlusCar::ComfortPlusCar() {
    Type = ComfortPlus;
}

BusinessCar::BusinessCar() {
    Type = Business;
}
