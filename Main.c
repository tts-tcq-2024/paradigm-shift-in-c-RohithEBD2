#include "battery_management_system.h"

int main() {
    WarningConfig config = {true, true, true}; // Enable warnings for all parameters

    // Test battery health with the current configuration
    if (batteryIsOk(25, 70, 0.7, &config)) {
        printf("Battery is OK\n");
    } else {
        printf("Battery is not OK\n");
    }

    return 0;
}
