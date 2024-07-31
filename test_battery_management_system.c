#include <assert.h>
#include <stdio.h>
#include "battery_management_system.h"

void testIsTemperatureInRange() {
    assert(isTemperatureInRange(0) == true);
    assert(isTemperatureInRange(45) == true);
    assert(isTemperatureInRange(25) == true);
    assert(isTemperatureInRange(-0.1) == false);
    assert(isTemperatureInRange(45.1) == false);
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

void testBatteryIsOk() {
    WarningConfig config = {true, true, true}; // Enable warnings for all parameters
    assert(batteryIsOk(25, 70, 0.7, &config) == true);
    assert(batteryIsOk(0, 20, 0, &config) == true);
    assert(batteryIsOk(-1, 70, 0.7, &config) == false);
    assert(batteryIsOk(25, 19, 0.7, &config) == false);
    assert(batteryIsOk(25, 70, 0.9, &config) == false);
    assert(batteryIsOk(50, 85, 0, &config) == false);
}

void testWarnings() {
    WarningConfig config = {true, true, true}; // Enable warnings for all parameters
    checkTemperatureWarning(43.5, &config); // High temperature warning
    checkTemperatureWarning(2.0, &config);  // Low temperature warning
    checkSocWarning(76.0, &config);         // High SOC warning
    checkSocWarning(22.0, &config);         // Low SOC warning
    checkChargeRateWarning(0.78, &config);  // High charge rate warning
}

int main() 
{
    testWarnings();
    testBatteryIsOk();
    testIsTemperatureInRange();
    testIsSocInRange();
    testIsChargeRateInRange();
    return 0;
}
