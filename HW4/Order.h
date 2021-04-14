//
// Created by nikae on 14.04.2021.
//

#ifndef WENDEX_ORDER_H
#define WENDEX_ORDER_H
#include "string"
#include "vector"

using namespace std;


class Order {
public:
    Order(string from, string to, string driverName, string passengerName, int price);
    string from;
    string to;
    string driverName;
    string passengerName;
    int price;
};


#endif //WENDEX_ORDER_H
