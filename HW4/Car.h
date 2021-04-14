//
// Created by nikae on 14.04.2021.
//

#ifndef WENDEX_CAR_H
#define WENDEX_CAR_H

#endif //WENDEX_CAR_H

#include "string"

enum CarType {
    Economy, Comfort, ComfortPlus, Business
};

class Car {
public:
    Car() = default;

protected:
    std::string model;
    CarType Type;
    std::pair<int, int> coordinates;
    std::string color;
    int number;
};

class ComfortCar : Car {
public:
    ComfortCar(int bottle);

private:
    int freeBottleOfWater;
};

class EconomyCar : Car {
public:
    EconomyCar();
};

class BusinessCar : Car {
public:
    BusinessCar();

private:
    void parkRightInFrontOfTheEntrance();
};

class ComfortPlusCar : Car {
public:
    ComfortPlusCar();
};

