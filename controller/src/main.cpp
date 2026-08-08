#ifdef PLATFORM_NATIVE_ILI
#include "platforms/nativeili.h"

#elif defined(PLATFORM_NATIVE_ST)
#include "platforms/nativest.h"

#elif defined(PLATFORM_ESP32S3)
#include "platforms/esp32_s3.h"

#else
#include "platforms/esp32_dev.h"
#endif
