#include <stdbool.h>

#define MIN_TEMPERATURE 0.0f
#define MAX_TEMPERATURE 45.0f
#define TEMPERATURE_WARNING_TOLERANCE 2.25f // 5% of 45

#define MIN_SOC 20.0f
#define MAX_SOC 80.0f
#define SOC_WARNING_TOLERANCE 4.0f // 5% of 80

#define MAX_CHARGE_RATE 0.8f
#define CHARGE_RATE_WARNING_TOLERANCE 0.04f // 5% of 0.8

typedef struct {
    float temperature;
    float soc;
    float chargeRate;
} BatteryManagementSystem;

bool isTemperatureInRange(float temperature);
bool isSocInRange(float soc);
bool isChargeRateInRange(float chargeRate);
bool batteryIsOk(float temperature, float soc, float chargeRate);
void logMessage(const char* message, float value, bool isHigh);
void checkTemperatureWarning(float temperature);
void checkSocWarning(float soc);
void checkChargeRateWarning(float chargeRate);

