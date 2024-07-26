#include "battery_state_of_charge.h"
#include "battery_management_system.h"

bool isSocInRange(float soc) {
    bool isLow = soc < MIN_SOC;
    bool isHigh = soc > MAX_SOC;

    if (isLow || isHigh) {
        logMessage("State of Charge out of range", soc, isHigh);
        return false;
    }
    return true;
}

void checkHighSocWarning(float soc) {
    bool isApproachingHigh = soc > MAX_SOC - SOC_WARNING_TOLERANCE && soc <= MAX_SOC;
    if (isApproachingHigh) {
        logMessage("Warning: Approaching charge-peak", soc, true);
    }
}

void checkLowSocWarning(float soc) {
    bool isApproachingLow = soc >= MIN_SOC && soc < MIN_SOC + SOC_WARNING_TOLERANCE;
    if (isApproachingLow) {
        logMessage("Warning: Approaching discharge", soc, false);
    }
}

void checkSocWarning(float soc, const WarningConfig* config) {
    checkHighSocWarning(soc);
    checkLowSocWarning(soc);
}
