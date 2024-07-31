#include "battery_management_system.h"
#include "battery_charge_rate.h"
#include "battery_temperature.h"
#include "battery_state_of_charge.h"
#include <stdio.h>

void logMessage(const char* message, float value, bool isHigh) {
    printf("%s: %.2f (%s)\n", message, value, isHigh ? "high" : "low");
}

bool batteryIsOk(float temperature, float soc, float chargeRate, const WarningConfig* config) {
    
    checkWarnings(temperature, soc, chargeRate, config);
    
    bool isOk = isTemperatureInRange(temperature) &&
                isSocInRange(soc) &&
                isChargeRateInRange(chargeRate);

    return isOk;
}

void checkWarnings(float temperature, float soc, float chargeRate, const WarningConfig* config) {
    checkTemperatureWarningIfEnabled(temperature, config);
    checkSocWarningIfEnabled(soc, config);
    checkChargeRateWarningIfEnabled(chargeRate, config);
}

void checkTemperatureWarningIfEnabled(float temperature, const WarningConfig* config) {
    if (config->enableTemperatureWarning) {
        checkTemperatureWarning(temperature, config);
    }
}

void checkSocWarningIfEnabled(float soc, const WarningConfig* config) {
    if (config->enableSocWarning) {
        checkSocWarning(soc, config);
    }
}

void checkChargeRateWarningIfEnabled(float chargeRate, const WarningConfig* config) {
    if (config->enableChargeRateWarning) {
        checkChargeRateWarning(chargeRate, config);
    }
}
