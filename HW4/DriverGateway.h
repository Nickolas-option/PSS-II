
#ifndef WENDEX_DRIVERGATEWAY_H
#define WENDEX_DRIVERGATEWAY_H

#endif //WENDEX_DRIVERGATEWAY_H

#include "string"
#include "vector"

using namespace std;

#include "DriverApp.h"
#include "Order.h"


class DriverGateway {
public:
    vector<Order> seeOrderHistory(DriverApp *Driver);

    void seeCar(DriverApp *Driver);

    void updateStatus(DriverApp *Driver, Status newStatus);

    vector<int> getOrderList(DriverApp *Driver);

    void acceptOrder(DriverApp *Driver, int OrderId);

    void declineOrder(DriverApp *Driver, int OrderId);
};