#include "battery_temperature.h"
#include "battery_log_message.h"

bool isTemperatureInRange(float temperature) {
    bool isLow = temperature < MIN_TEMPERATURE;
    bool isHigh = temperature > MAX_TEMPERATURE;

    if (isLow || isHigh) {
        logMessage("Temperature out of range", temperature, isHigh);
        return false;
    }
    return true;
}

void checkHighTemperatureWarning(float temperature) {
    bool isApproachingHigh = temperature > MAX_TEMPERATURE - TEMPERATURE_WARNING_TOLERANCE && temperature <= MAX_TEMPERATURE;
    if (isApproachingHigh) {
        logMessage("Warning: Approaching high temperature", temperature, true);
    }
}

void checkLowTemperatureWarning(float temperature) {
    bool isApproachingLow = temperature >= MIN_TEMPERATURE && temperature < MIN_TEMPERATURE + TEMPERATURE_WARNING_TOLERANCE;
    if (isApproachingLow) {
        logMessage("Warning: Approaching low temperature", temperature, false);
    }
}

void checkTemperatureWarning(float temperature, const WarningConfig* config) {
    checkHighTemperatureWarning(temperature);
    checkLowTemperatureWarning(temperature);
}
