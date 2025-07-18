# toolchain-mingw64.cmake
set(CMAKE_SYSTEM_NAME Windows)
set(CMAKE_SYSTEM_PROCESSOR x86_64) # Or i686 for 32-bit Windows

# Specify the cross compilers for MinGW-w64
set(CMAKE_C_COMPILER x86_64-w64-mingw32-gcc)
set(CMAKE_CXX_COMPILER x86_64-w64-mingw32-g++)
set(CMAKE_RC_COMPILER x86_64-w64-mingw32-windres) # For Windows resource files

# Adjust the default behavior of the find commands:
# Search headers and libraries in the target environment
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
# Search programs in the host environment (e.g., CMake itself, utilities)
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)

# Optional: Set the target system version (e.g., to use newer Windows APIs)
# set(CMAKE_SYSTEM_VERSION 10.0)