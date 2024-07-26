#include <stdbool.h>

#define MIN_TEMPERATURE 0.0f
#define MAX_TEMPERATURE 45.0f
#define TEMPERATURE_WARNING_TOLERANCE 2.25f // 5% of 45

bool isTemperatureInRange(float temperature);
void checkTemperatureWarning(float temperature, const WarningConfig* config);
void checkTemperatureWarningIfEnabled(float temperature, const WarningConfig* config);
