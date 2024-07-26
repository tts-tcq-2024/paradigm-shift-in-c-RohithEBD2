#include <stdbool.h>
#include "battery_management_system.h"

#define MIN_SOC 20.0f
#define MAX_SOC 80.0f
#define SOC_WARNING_TOLERANCE 4.0f // 5% of 80

bool isSocInRange(float soc);
void checkSocWarning(float soc, const WarningConfig* config);
void checkSocWarningIfEnabled(float soc, const WarningConfig* config);
