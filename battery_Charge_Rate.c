#include "battery_charge_rate.h"
#include "battery_management_system.h"

bool isChargeRateInRange(float chargeRate) {
    bool isHigh = chargeRate > MAX_CHARGE_RATE;

    if (isHigh) {
        logMessage("Charge Rate out of range", chargeRate, true);
        return false;
    }
    return true;
}

void checkChargeRateWarning(float chargeRate, const WarningConfig* config) {
    bool isApproachingHigh = chargeRate > MAX_CHARGE_RATE - CHARGE_RATE_WARNING_TOLERANCE && chargeRate <= MAX_CHARGE_RATE;
    if (isApproachingHigh) {
        logMessage("Warning: Approaching high charge rate", chargeRate, true);
    }
}
