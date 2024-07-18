#include <assert.h>
#include <stdio.h>
#include "battery_management_system.h"

void testIsTemperatureInRange() {
    assert(isTemperatureInRange(0) == true);
    assert(isTemperatureInRange(45) == true);
    assert(isTemperatureInRange(25) == true);
    assert(isTemperatureInRange(-0.1) == false);
    assert(isTemperatureInRange(45.1) == false);
    assert(isTemperatureInRange(-5) == false);
    assert(isTemperatureInRange(50) == false);
}

void testIsSocInRange() {
    assert(isSocInRange(20) == true);
    assert(isSocInRange(80) == true);
    assert(isSocInRange(50) == true);
    assert(isSocInRange(19.9) == false);
    assert(isSocInRange(80.1) == false);
    assert(isSocInRange(10) == false);
    assert(isSocInRange(90) == false);
}

void testIsChargeRateInRange() {
    assert(isChargeRateInRange(0.7) == true);
    assert(isChargeRateInRange(0) == true);
    assert(isChargeRateInRange(0.7) == true);
    assert(isChargeRateInRange(0.81) == false);
    assert(isChargeRateInRange(0.9) == false);
}

void testBatteryIsOk_1() {
    assert(batteryIsOk(25, 70, 0.7) == true);
    assert(batteryIsOk(0, 20, 0) == true);
    assert(batteryIsOk(-1, 70, 0.7) == false);
    assert(batteryIsOk(25, 19, 0.7) == false);
    assert(batteryIsOk(25, 70, 0.9) == false);
    assert(batteryIsOk(50, 85, 0) == false);
}

void testWarnings() {
    checkTemperatureWarning(43.5); // High temperature warning
    checkTemperatureWarning(2.0);  // Low temperature warning
    checkSocWarning(76.0);         // High SOC warning
    checkSocWarning(22.0);         // Low SOC warning
    checkChargeRateWarning(0.78);  // High charge rate warning
}

int main() {
    testIsTemperatureInRange();
    testIsSocInRange();
    testIsChargeRateInRange();
    testBatteryIsOk_1();
    testWarnings();
    printf("All tests passed!\n");
    return 0;
}
