//
// Created by nikae on 14.04.2021.
//

#include "Order.h"

Order::Order(string from, string to, string driverName, string passengerName, int price) {
    this->from = from;
    this->to = to;
    this->driverName = driverName;
    this->passengerName = passengerName;
    this->price = price;
}
