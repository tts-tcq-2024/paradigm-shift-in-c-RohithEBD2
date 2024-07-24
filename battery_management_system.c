#include "battery_management_system.h"
#include <stdio.h>

void logMessage(const char* message, float value, bool isHigh) {
    printf("%s: %.2f (%s)\n", message, value, isHigh ? "high" : "low");
}

bool batteryIsOk(float temperature, float soc, float chargeRate, const WarningConfig* config) {
    bool isOk = true;
    isOk &= isTemperatureInRange(temperature);
    isOk &= isSocInRange(soc);
    isOk &= isChargeRateInRange(chargeRate);

    if (config->enableTemperatureWarning) {
        checkTemperatureWarning(temperature, config);
    }
    if (config->enableSocWarning) {
        checkSocWarning(soc, config);
    }
    if (config->enableChargeRateWarning) {
        checkChargeRateWarning(chargeRate, config);
    }

    return isOk;
}
