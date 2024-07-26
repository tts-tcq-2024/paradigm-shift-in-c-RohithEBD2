#include <stdbool.h>

typedef struct {
    bool enableTemperatureWarning;
    bool enableSocWarning;
    bool enableChargeRateWarning;
} WarningConfig;


void logMessage(const char* message, float value, bool isHigh);
bool batteryIsOk(float temperature, float soc, float chargeRate, const WarningConfig* config);

void checkWarnings(float temperature, float soc, float chargeRate, const WarningConfig* config);





