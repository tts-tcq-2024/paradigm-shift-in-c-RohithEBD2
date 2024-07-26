#include <stdbool.h>

#define MAX_CHARGE_RATE 0.8f
#define CHARGE_RATE_WARNING_TOLERANCE 0.04f // 5% of 0.8

typedef struct {
    bool enableTemperatureWarning;
    bool enableSocWarning;
    bool enableChargeRateWarning;
} WarningConfig;




bool isChargeRateInRange(float chargeRate);
void checkChargeRateWarning(float chargeRate, const WarningConfig* config);

void logMessage(const char* message, float value, bool isHigh);
bool batteryIsOk(float temperature, float soc, float chargeRate, const WarningConfig* config);

void checkWarnings(float temperature, float soc, float chargeRate, const WarningConfig* config);

void checkChargeRateWarningIfEnabled(float chargeRate, const WarningConfig* config);



