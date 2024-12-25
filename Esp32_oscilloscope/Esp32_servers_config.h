#include "./servers/version_of_servers.h"

#define FILE_SYSTEM FILE_SYSTEM_LITTLEFS

#define DEFAULT_STA_SSID "ayman"
#define DEFAULT_STA_PASSWORD "8838692325"

#define HOSTNAME "ESP32_oscilloscope"

#if CONFIG_IDF_TARGET_ESP32
    #define MACHINETYPE "ESP32"
#elif CONFIG_IDF_TARGET_ESP32S2
    #define MACHINETYPE "ESP32-S2"
#elif CONFIG_IDF_TARGET_ESP32S3
    #define MACHINETYPE "ESP32-S3"
#elif CONFIG_IDF_TARGET_ESP32C3
    #define MACHINETYPE "ESP32-C3"
#elif CONFIG_IDF_TARGET_ESP32C6
    #define MACHINETYPE "ESP32-C6"
#elif CONFIG_IDF_TARGET_ESP32H2
    #define MACHINETYPE "ESP32-H2"
#else
    #define MACHINETYPE "ESP32 (other)"
#endif

#define USER_MANAGEMENT NO_USER_MANAGEMENT

#ifdef FILE_SYSTEM
    #include "./servers/fileSystem.hpp"
#endif
#include "./servers/time_functions.h"
#include "./servers/netwk.h"
#include "./servers/userManagement.hpp"
#ifdef FILE_SYSTEM
    #include "./servers/ftpServer.hpp"
#endif
#define USE_I2S_INTERFACE
#include "./servers/oscilloscope.h"
#include "./servers/httpServer.hpp"