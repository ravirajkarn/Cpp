# toolchain-mingw64.cmake
set(CMAKE_SYSTEM_NAME Windows)
set(CMAKE_SYSTEM_PROCESSOR x86_64)

# Specify the cross compiler
set(CMAKE_C_COMPILER x86_64-w64-mingw32-gcc)
set(CMAKE_CXX_COMPILER x86_64-w64-mingw32-g++)
# Optionally, of you have resource files(.rc)
set(CMAKE_RC_COMPILER x86_64-w64-mingw32-windres)

# Adjust the default behavior of the find commands:
# Search headers and libraries in the target environment
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
# Search programs in the build environment (e.g., CMake itself, utilities)
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)