cmake_minimum_required(VERSION 3.15) # Ninja generator often works better with newer CMake
project(MyMultiPlatformApp VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Define source files for our application
set(APP_SOURCES
    src/main.cpp
    src/util.cpp
)

# Create the executable target
add_executable(MyMultiPlatformApp ${APP_SOURCES})

# --- Platform-specific configurations ---

# For Windows (when cross-compiling from Linux)
if(WIN32)
    message(STATUS "Configuring for Windows target...")
    # Example: Link against a Windows-specific library if needed
    # For a simple console app, often no extra links are needed
    # target_link_libraries(MyMultiPlatformApp PRIVATE ws2_32 advapi32) # Example for network/system calls
    
    # You might also want to set output directory for Windows executables
    set_target_properties(MyMultiPlatformApp PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/windows"
    )

elseif(UNIX)
    message(STATUS "Configuring for Linux target...")
    # Example: Link against a common Unix/Linux library if needed (e.g., pthreads for multi-threading)
    # target_link_libraries(MyMultiPlatformApp PRIVATE pthread)
    
    # Set output directory for Linux executables
    set_target_properties(MyMultiPlatformApp PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/linux"
    )

endif()

# Set general output directory for the whole project structure
# This ensures build artifacts go into build/<config> folders.
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")