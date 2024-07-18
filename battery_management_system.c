#include "battery_management_system.h"
#include <stdio.h>

void logMessage(const char* message, float value, bool isHigh) {
    printf("%s: %.2f (%s)\n", message, value, isHigh ? "high" : "low");
}

bool isTemperatureInRange(float temperature) {
    if (temperature < MIN_TEMPERATURE || temperature > MAX_TEMPERATURE) {
        logMessage("Temperature out of range", temperature, temperature > MAX_TEMPERATURE);
        return false;
    }
    return true;
}

void checkTemperatureWarning(float temperature) {
    if (temperature > MAX_TEMPERATURE - TEMPERATURE_WARNING_TOLERANCE && temperature <= MAX_TEMPERATURE) {
        logMessage("Warning: Approaching high temperature", temperature, true);
    } else if (temperature >= MIN_TEMPERATURE && temperature < MIN_TEMPERATURE + TEMPERATURE_WARNING_TOLERANCE) {
        logMessage("Warning: Approaching low temperature", temperature, false);
    }
}

bool isSocInRange(float soc) {
    if (soc < MIN_SOC || soc > MAX_SOC) {
        logMessage("State of Charge out of range", soc, soc > MAX_SOC);
        return false;
    }
    return true;
}

void checkSocWarning(float soc) {
    if (soc > MAX_SOC - SOC_WARNING_TOLERANCE && soc <= MAX_SOC) {
        logMessage("Warning: Approaching charge-peak", soc, true);
    } else if (soc >= MIN_SOC && soc < MIN_SOC + SOC_WARNING_TOLERANCE) {
        logMessage("Warning: Approaching discharge", soc, false);
    }
}

bool isChargeRateInRange(float chargeRate) {
    if (chargeRate > MAX_CHARGE_RATE) {
        logMessage("Charge Rate out of range", chargeRate, true);
        return false;
    }
    return true;
}

void checkChargeRateWarning(float chargeRate) {
    if (chargeRate > MAX_CHARGE_RATE - CHARGE_RATE_WARNING_TOLERANCE && chargeRate <= MAX_CHARGE_RATE) {
        logMessage("Warning: Approaching high charge rate", chargeRate, true);
    }
}

bool batteryIsOk_1(float temperature, float soc, float chargeRate) {
    bool isOk = true;
    isOk &= isTemperatureInRange(temperature);
    isOk &= isSocInRange(soc);
    isOk &= isChargeRateInRange(chargeRate);
    
    checkTemperatureWarning(temperature);
    checkSocWarning(soc);
    checkChargeRateWarning(chargeRate);
    
    return isOk;
}
