
#ifndef WENDEX_CAR_H
#define WENDEX_CAR_H
#include "string"
#include "vector"


using namespace std;


class Car {
public:
    Car() = default;

    enum CarType {
        Economy, Comfort, ComfortPlus, Business
    };

    static string printCarType(CarType carType);
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

#endif //WENDEX_CAR_H