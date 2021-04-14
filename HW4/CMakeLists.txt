cmake_minimum_required(VERSION 3.17)
project(WEndex)

set(CMAKE_CXX_STANDARD 20)

add_executable(WEndex main.cpp PassengerApp.cpp PassengerApp.h DriverApp.cpp DriverApp.h PassengerGateway.cpp PassengerGateway.h DriverGateway.cpp DriverGateway.h Car.cpp Car.h Order.cpp Order.h)