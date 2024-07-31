#ifndef BATTERY_MANAGEMENT_SYSTEM_H
#define BATTERY_MANAGEMENT_SYSTEM_H

#include <stdbool.h>

typedef struct {
    bool enableTemperatureWarning;
    bool enableSocWarning;
    bool enableChargeRateWarning;
} WarningConfig;

bool batteryIsOk(float temperature, float soc, float chargeRate, const WarningConfig* config);

void checkWarnings(float temperature, float soc, float chargeRate, const WarningConfig* config);

#endif // BATTERY_MANAGEMENT_SYSTEM_H
