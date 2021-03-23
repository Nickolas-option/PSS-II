#include <iostream>
#include "Emergency.h"

void Emergency::startEmergency() {
    emergencyState = true;
}

void Emergency::finishEmergency(User &person) {
    if (person.getCard().cardLevel == redLevel) {
        emergencyState = false;
        cout << "Emergency stopped by " + person.getName() +"!\n";
    } else {
        cout << "No access to changing emergency state for " + person.getName() +"!\n";
    }
}

bool Emergency::isEmergency() {
    return emergencyState;
}

void Emergency::initializeEmergency() {
    Emergency();
}

