#ifndef HW3_EMERGENCY_H
#define HW3_EMERGENCY_H
#endif //HW3_EMERGENCY_H
#include "User.h"
class Emergency {
public:
    static void startEmergency();

    static void finishEmergency(User& person);

    static bool isEmergency();

    static void initializeEmergency();

private:
    inline static bool emergencyState = false;
};