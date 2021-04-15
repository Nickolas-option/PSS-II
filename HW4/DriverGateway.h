
#ifndef WENDEX_DRIVERGATEWAY_H
#define WENDEX_DRIVERGATEWAY_H

#include "string"
#include "vector"
#include "DriverApp.h"
#include "Order.h"

using namespace std;

class DriverGateway {
public:
    inline static vector<DriverApp> driversList {};
    inline static vector<vector<Order>> driversOrderHistories {};

    vector<Order> seeOrderHistory(DriverApp *Driver);

    void seeCar(DriverApp *Driver);

    void updateStatus(DriverApp *Driver, Status newStatus);

    vector<int> getOrderList(DriverApp *Driver);

    void acceptOrder(DriverApp *Driver, int OrderId);

    void declineOrder(DriverApp *Driver, int OrderId);

    friend class PassengerGateway;
};

#endif //WENDEX_DRIVERGATEWAY_H