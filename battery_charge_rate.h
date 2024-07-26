#include <stdbool.h>
#include "battery_management_system.h"

#define MAX_CHARGE_RATE 0.8f
#define CHARGE_RATE_WARNING_TOLERANCE 0.04f // 5% of 0.8

bool isChargeRateInRange(float chargeRate);
void checkChargeRateWarning(float chargeRate, const WarningConfig* config);
void checkChargeRateWarningIfEnabled(float chargeRate, const WarningConfig* config);
