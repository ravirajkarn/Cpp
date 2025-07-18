#include "util.h"

// Include platform-specific headers if needed
#ifdef _WIN32
#include <windows.h> // Example Windows-specific header
#else
#include <unistd.h>  // Example Linux-specific header
#endif

std::string getPlatformMessage() {
#ifdef _WIN32
    return "Hello from Windows (Built on Linux)!";
#elif __linux__
    return "Hello from Linux (Native Build)!";
#else
    return "Hello from an unknown platform!";
#endif
}